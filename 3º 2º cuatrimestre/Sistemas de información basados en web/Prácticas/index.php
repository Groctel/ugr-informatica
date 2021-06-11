<?php
ini_set('display_errors', 1);

require_once('vendor/autoload.php');
require('scripts_php/database/event.php');
require('scripts_php/database/user.php');

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig   = new \Twig\Environment($loader);

session_start();

$events = db_event::event_table();
$user   = [];

if (isset($_SESSION['user_id']))
	$user = db_user::get($_SESSION['user_id']);

echo $twig->render('index.html', [
	'user'   => $user,
	'events' => $events,
]);
?>
