<?php

    // configuration
    require("../includes/config.php");
    
    // create an associative array for positions to hold array created by the lookup function
    $positions = [];
    
    // query the symbols and shares from the database
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    // create an associative array for the selected symbol
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        
        
        if($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => $stock["price"] * $row["shares"]
            ];
        }
    }
    
    // if the request method is post, delete the data entry for the chosen symbol and update the cash balance
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $positions[0]["total"], $_SESSION["id"]);
        CS50::query("INSERT INTO history (user_id, symbol, shares, price, action) VALUES(?, ?, ?, ?, ?)", $_SESSION["id"], $_POST["symbol"], $row["shares"], $positions[0]["price"], "SELL");
        
        // redirect to portfolio
        redirect("index.php");
    }
        
    render("sell_form.php", ["positions" => $positions, "title" => "Sell"]);
    
?>