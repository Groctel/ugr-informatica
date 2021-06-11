<?php
ini_set('display_errors', 1);

require_once('../vendor/autoload.php');
require('database/user.php');

$loader = new \Twig\Loader\FilesystemLoader('../templates');
$twig   = new \Twig\Environment($loader);

session_start();
$user = db_user::get($_SESSION['user_id']);

$form_status = array(
	'dupli_mail' => true,
	'mail'       => $_POST['mail'],
	'valid_mail' => false,
	'valid_pass' => false,
	'used'       => true,
);

if ($user['id'] == db_user::login($user['mail'], $_POST['pass']))
{
	$form_status['valid_pass'] = true;

	if (!empty($form_status['mail']))
	{
		$form_status['valid_mail'] = db_core::is_mail($form_status['mail']);
		$form_status['dupli_mail'] = db_user::mail_exists($form_status['mail']);

		if ($form_status['valid_mail'] && !$form_status['dupli_mail'])
			db_user::update_mail($user['id'], $form_status['mail']);
	}

	if (!empty($_POST['newpass']))
		db_user::update_pass($user['id'], password_hash($_POST['newpass'], PASSWORD_BCRYPT));
}

$_SESSION['update_account_form'] = $form_status;
header("Location: ../account.php");
exit();
?>
