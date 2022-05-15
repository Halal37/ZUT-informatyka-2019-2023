<?php
    $mysqli = mysqli_connect("localhost","root","","labs");
    $res = mysqli_query($mysqli, "SELECT fname as _msg from customers");
    $row = mysqli_fetch_assoc($res);
    echo $row['_msg'];
?>