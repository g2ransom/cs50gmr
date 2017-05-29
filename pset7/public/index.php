<?php

    // configuration
    require("../includes/config.php");
    
    $positions = [];
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    $cash_row = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $cash = $cash_row[0]['cash'];
    
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
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
    
   

    // render portfolio
    render("portfolio.php", ["cash" => $cash, "positions" => $positions, "title" => "Portfolio"]);

?>
