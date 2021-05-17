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

	if (isset($_SESSION['user_id']))
	{
		$user = user_data($_SESSION['user_id']);
		$has_access = ($user['perm'] == 'manager' || $user['perm'] == 'superuser');
	}

	if ($has_access && isset($_GET['event_id']))
	{
		$event_id = $_GET['event_id'];
		$event    = event_row($event_id);

		if ($_SERVER['REQUEST_METHOD'] === 'POST')
		{
			$form_used = true;

			if (isset($_GET['delete']))
			{
				delete_event($_GET['event_id']);
				header("Location: index.php");
			}
			else
			{
				$event['title'] = $_POST['title'];
				$event['date']  = $_POST['date'];
				$event['desc']  = $_POST['desc'];
				$event['img1']  = $_POST['img1'];
				$event['img2']  = $_POST['img2'];

				if (!empty($title) && !empty($date) && !empty($desc) && !empty($img1) && !empty($img2))
				{
					update_event($user['id'], $title, $date, $desc, $img1, $img2);
					header("Location: evento.php?event_id=". $event_id);
				}
			}
		}

		echo $twig->render('editevent.html', [
			'user'      => $user,
			'form_used' => $form_used,
			'event'     => $event,
		]);
	}
	else
	{
		echo $twig->render('error_404.html', []);
	}
?>

