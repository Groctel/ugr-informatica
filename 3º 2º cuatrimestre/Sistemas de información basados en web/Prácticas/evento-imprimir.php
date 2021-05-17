<?php
	ini_set('display_errors', 1);
	require_once "/usr/local/lib/php/vendor/autoload.php";
	include("scripts_php/database.php");

	$loader = new \Twig\Loader\FilesystemLoader('templates');
	$twig = new \Twig\Environment($loader);

	$event_id = "";

	if (isset($_GET['event_id']))
		$event_id = $_GET['event_id'];

	$event = event_row($event_id);

	$event['desc'] = preg_replace("/^/", "<p>", $event['desc']);
	$event['desc'] = preg_replace("/$/", "</p>", $event['desc']);
	$event['desc'] = str_replace("\r\n\r\n", "</p><p>", $event['desc']);

	if ($event['id'] != '0')
		echo $twig->render('evento-imprimir.html', [
			'event'    => $event,
			'org'      => user_data($event['id_org'])['name'],
		]);
	else
		echo $twig->render('error_404.html', []);
?>
