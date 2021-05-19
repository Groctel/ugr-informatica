<?php
ini_set('display_errors', 1);

require_once('vendor/autoload.php');
require("scripts_php/database/event.php");
require("scripts_php/database/user.php");

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig   = new \Twig\Environment($loader);

$event = db_event::get($_GET['event_id']);

if ($event['id'] != '-1')
{
	$event['desc'] = preg_replace("/^/",     "<p>",     $event['desc']);
	$event['desc'] = preg_replace("/$/",     "</p>",    $event['desc']);
	$event['desc'] = str_replace("\r\n\r\n", "</p><p>", $event['desc']);

	echo $twig->render('evento_imprimir.html', [
		'event' => $event,
		'org'   => db_user::get($event['id_org'])['name'],
	]);
}
else
	echo $twig->render('error_404.html', []);
?>
