<?php
	ini_set('display_errors', 1);
	require_once "/usr/local/lib/php/vendor/autoload.php";
	include("database.php");

	$loader = new \Twig\Loader\FilesystemLoader('templates');
	$twig = new \Twig\Environment($loader);

	$event_id = "";

	if (isset($_GET['event_id']))
		$event_id = $_GET['event_id'];

	$event = event_row($event_id);

	$event['descripción'] =  preg_replace("/^/", "<p>", $event['descripción']);
	$event['descripción'] =  preg_replace("/$/", "</p>", $event['descripción']);
	$event['descripción'] =  str_replace("\r\n\r\n", "</p><p>", $event['descripción']);

	$comments = comment_table($event_id);

	if ($event['id'] != '0')
		echo $twig->render('evento.html', ['event' => $event, 'comments' => $comments]);
	else
		echo $twig->render('error_404.html', []);
?>
