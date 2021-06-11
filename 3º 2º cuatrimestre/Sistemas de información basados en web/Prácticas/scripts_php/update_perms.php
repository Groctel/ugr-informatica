<?php
ini_set('display_errors', 1);

require_once('../vendor/autoload.php');
require('database/user.php');

$loader = new \Twig\Loader\FilesystemLoader('../templates');
$twig   = new \Twig\Environment($loader);

session_start();
$user = db_user::get($_SESSION['user_id']);

$form_status = array(
	'valid_pass' => false,
	'used'       => true,
);

if ($user['id'] == db_user::login($user['mail'], $_POST['pass']))
{
	$form_status['valid_pass'] = true;
	db_user::update_perm($_GET['user_id'], $_POST['perm']);
}

$_SESSION['update_perms_form'] = $form_status;
header("Location: ../account.php?user_id=" . $_GET['user_id']);
exit();
?>
