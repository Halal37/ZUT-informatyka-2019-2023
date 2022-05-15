<?php
    $mysqli = new mysqli("localhost","root","","labs");
    if ($mysqli->connect_errno){
        echo "Failed to connect to MySQL: " . $mysqli->connect_error;
    }

    $res = $mysqli->query("SELECT * from customers");
    if (!$res) {
        echo "Failed to run query: (" .$mysqli->errno . ") " . $mysqli->error;
    }

    if ($row = $res->fetch_assoc()){
        echo $row['customerName'];
    }

 
?>