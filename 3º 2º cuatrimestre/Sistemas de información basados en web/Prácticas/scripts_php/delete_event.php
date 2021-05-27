<?php
ini_set('display_errors', 1);

require_once("../vendor/autoload.php");
require("database/event.php");
require("database/user.php");

$loader = new \Twig\Loader\FilesystemLoader('../templates');
$twig   = new \Twig\Environment($loader);

session_start();

$user = db_user::get($_SESSION['user_id']);

if (db_user::perm_geq($user['perm'], 'manager'))
	db_event::delete($_GET['event_id']);

header("Location: ../index.php");
?>
