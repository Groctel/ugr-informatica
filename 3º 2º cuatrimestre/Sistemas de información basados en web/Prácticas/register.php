<?php
ini_set('display_errors', 1);

require_once('vendor/autoload.php');
include('scripts_php/database/user.php');

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig   = new \Twig\Environment($loader);

$form_status = array(
	'dupli_mail' => false,
	'mail'       => '',
	'name'       => '',
	'used'       => false,
	'valid_pass' => false,
	'valid_mail' => false,
);

if ($_SERVER['REQUEST_METHOD'] === 'POST')
{
	$form_status['used']       = true;
	$form_status['name']       = $_POST['name'];
	$form_status['mail']       = $_POST['mail'];
	$form_status['valid_pass'] = !empty($_POST['pass']);

	if (!empty($form_status['mail']))
	{
		$form_status['valid_mail'] = db_core::is_mail($form_status['mail']);
		$form_status['dupli_mail'] = db_user::mail_exists($form_status['mail']);
	}

	if (!empty($form_status['name']) && $form_status['valid_mail'] &&
		!$form_status['dupli_mail']   && $form_status['valid_pass'])
	{
		$id = db_user::register(
			$form_status['name'],
			$form_status['mail'],
			password_hash($_POST['pass'], PASSWORD_BCRYPT)
		);

		session_start();
		$_SESSION['user_id'] = $id;
		header("Location: index.php");
		exit();
	}
}

echo $twig->render('register.html', ['form_status' => $form_status]);
?>
