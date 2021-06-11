<?php
ini_set('display_errors', 1);

session_start();
session_destroy();
header("Location: ../index.php");
exit();
?>
