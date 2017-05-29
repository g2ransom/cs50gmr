<?php

    // configuration
    require("../includes/config.php");
    
    // create an associative array for positions to hold array created by the lookup function
    $positions = [];
    
    // query the symbols and shares from the database
    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    
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
                "action" => $row["action"],
                "time" => $row["time"]
            ];
        }
    }
    
    render("history_form.php", ["title" => "History", "positions" => $positions]);

?>