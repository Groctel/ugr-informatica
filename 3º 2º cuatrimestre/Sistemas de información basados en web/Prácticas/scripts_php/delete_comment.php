<?php
ini_set('display_errors', 1);

require_once("../vendor/autoload.php");
require("database/comment.php");
require("database/user.php");

$loader = new \Twig\Loader\FilesystemLoader('../templates');
$twig   = new \Twig\Environment($loader);

session_start();

$user = db_user::get($_SESSION['user_id']);

if (db_user::perm_geq($user['perm'], 'moderator'))
	db_comment::delete($_GET['comment_id']);

header("Location: ../evento.php?event_id=" . $_GET['event_id']);
?>

