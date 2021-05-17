<?php
	ini_set('display_errors', 1);
	require_once "/usr/local/lib/php/vendor/autoload.php";
	include("scripts_php/database.php");

	$loader = new \Twig\Loader\FilesystemLoader('templates');
	$twig = new \Twig\Environment($loader);

	session_start();

	$comment  = "";
	$event_id = "";
	$user = [];

	if (isset($_GET['event_id']))
		$event_id = $_GET['event_id'];

	if (isset($_SESSION['user_id']))
		$user = user_data($_SESSION['user_id']);

	if ($_SERVER['REQUEST_METHOD'] === 'POST')
	{
		$form_used = true;
		$comment   = $_POST['comment'];

		add_comment($event_id, $user['id'], $comment);
	}

	$event = event_row($event_id);

	$event['desc'] = preg_replace("/^/", "<p>", $event['desc']);
	$event['desc'] = preg_replace("/$/", "</p>", $event['desc']);
	$event['desc'] = str_replace("\r\n\r\n", "</p><p>", $event['desc']);

	$comments = comment_table($event_id);

	if ($event['id'] != '0')
		echo $twig->render('evento.html', [
			'event'    => $event,
			'org'      => user_data($event['id_org'])['name'],
			'comments' => $comments,
			'user'     => $user,
			'comment'  => $comment,
		]);
	else
		echo $twig->render('error_404.html', []);
?>
