<?php
    
    // configuration
    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["symbol"]))
        {
            apologize("Sorry. Please enter a symbol.");
        }
        
        $stock = lookup($_POST["symbol"]);
        

        if($stock === false)
        {
            apologize("Sorry. You entered an invalid symbol");
            
        }
        
        // render view for quote.php
        render("quote_result.php", ["stock" => $stock, "title" => "Quote"]);
    }
        // else, render view for quote_form.php
        render("quote_form.php", ["title" => "Quote"]);    
        
?>