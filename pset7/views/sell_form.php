<form action="sell.php" method="post"
<fieldset>
    <div>
        <select name = "symbol">
        <?php foreach ($positions as $position): ?>
            <option name="<?= $position["symbol"] ?>"><?= $position["symbol"] ?></option>
        <?php endforeach ?>
        </select>
    </div>
    <div class="form-group">
        <button class="btn btn-default" type="submit">
            <span aria-hidden="true"></span>
            Sell
        </button>
    </div>
</fieldset>