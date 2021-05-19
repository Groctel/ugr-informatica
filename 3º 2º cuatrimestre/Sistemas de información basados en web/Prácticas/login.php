<?php
ini_set('display_errors', 1);

require_once("vendor/autoload.php");
include('scripts_php/database/user.php');

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig   = new \Twig\Environment($loader);

$form_status = array(
	'mail' => '',
	'used' => false,
);

if ($_SERVER['REQUEST_METHOD'] === 'POST')
{
	$form_status['used'] = true;
	$form_status['mail'] = $_POST['mail'];

	$id = db_user::login($form_status['mail'], $_POST['pass']);

	if (!empty($id))
	{
		session_start();
		$_SESSION['user_id'] = $id;

		header("Location: index.php");
		exit();
	}
}

echo $twig->render('login.html', ['form_status' => $form_status]);
?>
