<?php

    // configuration
    require("../includes/config.php");
    
    // create an associative array for positions to hold array created by the lookup function
    $positions = [];
    
    $cash_row = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $cash = $cash_row[0]['cash'];
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["symbol"]))
        {
            apologize("Please enter a stock symbol.");
        }
        
        if(empty($_POST["shares"]))
        {
            apologize("Please enter the amount of shares that you'd like to purchase.");
        }
        
        // lookup the stock and make sure it's valid
        $stock = lookup($_POST["symbol"]);
        
        if($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $_POST["shares"],
                "symbol" => $_POST["symbol"],
                "total" => $stock["price"] * $_POST["shares"]
            ];
            
            // if shares are not a non-negative integer, apologize
            if(preg_match("/^\d+$/", $_POST["shares"]) == false)
            {
                apologize("Please enter a non-negative integer for shares.");
            }
            
            
            // if "total" is greater than cash, return false
            if($positions[0]["total"] > $cash)
            {
                apologize("You do not have enough cash to make this purchase.");
            }
            
            CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"]);
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $positions[0]["total"], $_SESSION["id"]);
            CS50::query("INSERT INTO history (user_id, symbol, shares, price, action) VALUES(?, ?, ?, ?, ?)", $_SESSION["id"], $_POST["symbol"], $_POST["shares"], $positions[0]["price"], "BUY");
            
            redirect("index.php");
        }
        
        else
        {
            apologize("Please enter a valid symbol.");
        }
    }

    render("buy_form.php", ["title" => "Buy"]);
?>