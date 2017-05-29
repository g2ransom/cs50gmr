<table class="table table-hover">
    <th>Symbol</th>
    <th>Name</th>
    <th>Shares</th>
    <th>Price</th>
    <th>Action</th>
    <th>Time</th>

    <tbody class="text-left">
        <?php

            foreach ($positions as $position) 
            {
                print("<tr>");
                print("<td>" . $position["symbol"] . "</td>");
                print("<td>" . $position["name"] . "</td>");
                print("<td>" . $position["shares"] . "</td>");
                print("<td>" . $position["price"] . "</td>");
                print("<td>" . $position["action"] . "</td>");
                print("<td>" . $position["time"] . "</td>");
                print("</tr>");
            }
            
        ?>
    
    </tbody>
    
</table>