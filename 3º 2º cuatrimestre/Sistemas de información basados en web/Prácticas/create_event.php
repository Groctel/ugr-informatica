<?php
ini_set('display_errors', 1);

require_once('vendor/autoload.php');
require('scripts_php/database/event.php');
require('scripts_php/database/user.php');

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig   = new \Twig\Environment($loader);

session_start();

$form_status = array(
	'date'  => '',
	'body'  => '',
	'img1'  => '',
	'img2'  => '',
	'tags'  => '',
	'title' => '',
	'used'  => false,
);

$user = db_user::get($_SESSION['user_id']);

if (db_user::perm_geq($user['perm'], 'manager'))
{
	if ($_SERVER['REQUEST_METHOD'] === 'POST')
	{
		$form_status['date']   = $_POST['date'];
		$form_status['body']   = $_POST['body'];
		$form_status['hidden'] = isset($_POST['hidden']);
		$form_status['img1']   = $_POST['img1'];
		$form_status['img2']   = $_POST['img2'];
		$form_status['tags']   = $_POST['tags'];
		$form_status['title']  = $_POST['title'];
		$form_status['used']   = true;


		if (!empty($form_status['title']) && !empty($form_status['date']) &&
			!empty($form_status['body']) && !empty($form_status['img1']) &&
			!empty($form_status['img2'])
		) {
			if (empty($form_status['hidden']))
				$form_status['hidden'] = 0;

			$event_id = db_event::insert($form_status, $user['id']);
			header("Location: evento.php?event_id=". $event_id);
			exit();
		}
	}

	echo $twig->render('create_event.html', [
		'user'        => $user,
		'form_status' => $form_status,
	]);
}
else
{
	echo $twig->render('error_404.html', []);
}
?>
