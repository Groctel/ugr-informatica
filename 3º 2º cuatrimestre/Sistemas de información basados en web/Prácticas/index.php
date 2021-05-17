<?php
	ini_set('display_errors', 1);
	require_once "./vendor/autoload.php";
	include('scripts_php/database.php');

	$loader = new \Twig\Loader\FilesystemLoader('templates');
	$twig   = new \Twig\Environment($loader);

	session_start();

	$event_list = event_table();
	$user = [];

	if (isset($_SESSION['user_id']))
		$user = user_data($_SESSION['user_id']);

	echo $twig->render('index.html', [
		'user'       => $user,
		'event_list' => $event_list,
	]);
?>
