<?php
ini_set('display_errors', 1);

require_once('vendor/autoload.php');
require("scripts_php/database/comment.php");
require("scripts_php/database/event.php");
require("scripts_php/database/user.php");

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig   = new \Twig\Environment($loader);

$user = [];

session_start();

if (isset($_SESSION['user_id']))
	$user = db_user::get($_SESSION['user_id']);

$event = db_event::get($_GET['event_id']);

if ($event['id'] != '-1')
{
	$event['body'] = preg_replace("/^/",     "<p>",     $event['body']);
	$event['body'] = preg_replace("/$/",     "</p>",    $event['body']);
	$event['body'] = str_replace("\r\n\r\n", "</p><p>", $event['body']);

	$comments = db_comment::get_from_event($event['id']);
	$tags     = db_tag::get_from_event($event['id']);

	echo $twig->render('evento.html', [
		'event'    => $event,
		'org'      => db_user::get($event['id_org'])['name'],
		'comments' => $comments,
		'user'     => $user,
		'tags'     => $tags,
	]);
}
else
	echo $twig->render('error_404.html', []);
?>
