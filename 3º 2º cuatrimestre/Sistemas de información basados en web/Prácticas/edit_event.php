<?php
ini_set('display_errors', 1);

require_once('vendor/autoload.php');
require('scripts_php/database/event.php');
require('scripts_php/database/user.php');

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig   = new \Twig\Environment($loader);

session_start();

$form_used = false;

$user = db_user::get($_SESSION['user_id']);

if (db_user::perm_geq($user['perm'], 'manager') && isset($_GET['event_id']))
{
	$event = db_event::get($_GET['event_id']);
	$tags  = implode(", ", db_tag::get_from_event($event['id']));

	if ($_SERVER['REQUEST_METHOD'] === 'POST')
	{
		$form_used = true;

		$event['title'] = $_POST['title'];
		$event['date']  = $_POST['date'];
		$event['body']  = $_POST['body'];
		$event['img1']  = $_POST['img1'];
		$event['img2']  = $_POST['img2'];
		$tags           = $_POST['tags'];

		if (!empty($event['title']) && !empty($event['date']) &&
			!empty($event['body']) && !empty($event['img1']) &&
			!empty($event['img2'])
		) {
			db_event::update($event, $tags);
			header("Location: evento.php?event_id=". $event['id']);
			exit();
		}
	}

	echo $twig->render('edit_event.html', [
		'user'      => $user,
		'form_used' => $form_used,
		'event'     => $event,
		'tags'      => $tags,
	]);
}
else
{
	echo $twig->render('error_404.html', []);
}
?>
