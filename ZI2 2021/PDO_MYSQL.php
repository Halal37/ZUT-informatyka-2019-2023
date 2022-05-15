<?php

$dsn = "mysql:host=localhost;dbname=labs";
$user = "root";
$passwd = "";

$pdo = new PDO($dsn, $user, $passwd);
$stm = $pdo->query("SELECT * FROM customers");
$rows = $stm->fetchAll(PDO::FETCH_ASSOC);

foreach($rows as $row) {
    printf("{$row['id']} {$row['customerName']} {$row['creditLimit']}\n");
}

?>