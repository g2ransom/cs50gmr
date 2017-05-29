<table class="table table-hover">
    <th>Symbol</th>
    <th>Name</th>
    <th>Shares</th>
    <th>Price</th>
    <th>Total</th>

    <tbody class="text-left">
        <?php

            foreach ($positions as $position) 
            {
                print("<tr>");
                print("<td>" . $position["symbol"] . "</td>");
                print("<td>" . $position["name"] . "</td>");
                print("<td>" . $position["shares"] . "</td>");
                print("<td>" . $position["price"] . "</td>");
                print("<td>" . number_format($position["total"], 2) . "</td>");
                print("</tr>");
            }
            
            print("<tr>");
            print("<td>" . "CASH" . "</td>");
            print("<td>" . "</td>");
            print("<td>" . "</td>");
            print("<td>" . "</td>");
            print("<td>" . number_format($cash, 2) . "</td>");
            print("<tr>");

        ?>

    </tbody>

</table>
