<?php
	ini_set('display_errors', 1);
	require_once "./vendor/autoload.php";
	include('scripts_php/database.php');

	$loader = new \Twig\Loader\FilesystemLoader('templates');
	$twig   = new \Twig\Environment($loader);

	session_start();

	$has_access = false;
	$user = [];

	$form_used = false;
	$title     = "";
	$date      = "";
	$desc      = "";
	$img1      = "";
	$img1      = "";

	if (isset($_SESSION['user_id']))
	{
		$user = user_data($_SESSION['user_id']);
		$has_access = ($user['perm'] == 'manager' || $user['perm'] == 'superuser');
	}

	if ($has_access)
	{
		if ($_SERVER['REQUEST_METHOD'] === 'POST')
		{
			$form_used = true;

			$title = $_POST['title'];
			$date  = $_POST['date'];
			$desc  = $_POST['desc'];
			$img1  = $_POST['img1'];
			$img2  = $_POST['img2'];

			if (!empty($title) && !empty($date) && !empty($desc) && !empty($img1) && !empty($img2))
			{
				$event_id = create_event($user['id'], $title, $date, $desc, $img1, $img2);

				header("Location: evento.php?event_id=". $event_id);
			}
		}

		echo $twig->render('newevent.html', [
			'user'      => $user,
			'form_used' => $form_used,
			'title'     => $title,
			'date'      => $date,
			'desc'      => $desc,
			'img1'      => $img1,
			'img2'      => $img2,
		]);
	}
	else
	{
		echo $twig->render('error_404.html', []);
	}
?>
