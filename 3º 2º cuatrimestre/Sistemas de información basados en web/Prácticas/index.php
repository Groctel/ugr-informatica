<?php
	require_once "./vendor/autoload.php";
	include('database.php');

	$loader = new \Twig\Loader\FilesystemLoader('templates');
	$twig = new \Twig\Environment($loader);

	$event_list = event_table();

	echo $twig->render('index.html', ['event_list' => $event_list]);
?>
