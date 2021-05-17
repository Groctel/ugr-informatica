<?php
	ini_set('display_errors', 1);
	require_once "/usr/local/lib/php/vendor/autoload.php";
	include("database.php");

	$loader = new \Twig\Loader\FilesystemLoader('../templates');
	$twig = new \Twig\Environment($loader);

	session_start();

	$comment_id = "";
	$event_id   = "";
	$user = [];

	if (isset($_SESSION['user_id']))
		$user = user_data($_SESSION['user_id']);

	if ($user['perm'] == 'moderator' || $user['perm'] == 'superuser')
	{

		if (isset($_GET['comment_id']))
			$comment_id = $_GET['comment_id'];

		if (!empty($comment_id))
			delete_comment($comment_id);
	}

	if (isset($_GET['event_id']))
		$event_id = $_GET['event_id'];

	header("Location: ../evento.php?event_id=" . $event_id);
?>
