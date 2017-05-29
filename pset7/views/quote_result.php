<?php
    
    // print the price in the correct format
    print "A share of " . $stock["name"] . " (" . $stock["symbol"] . ") costs: " . number_format($stock["price"] , 2) . ".";

?>