<?php
ini_set('display_errors', 1);

require_once('vendor/autoload.php');
require('scripts_php/database/user.php');

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig   = new \Twig\Environment($loader);

session_start();

if (isset($_SESSION['user_id']))
{
	$user         = db_user::get($_SESSION['user_id']);
	$user_queried = $user;
	$form_status  = [];

	if (isset($_SESSION['update_account_form']))
		$form_status = $_SESSION['update_account_form'];
	else if (isset($_SESSION['update_perms_form']))
		$form_status = $_SESSION['update_perms_form'];

	if (isset($_GET['id']))
		$user_queried = db_user::get($_GET['id']);


	echo $twig->render('account.html', [
		'user'         => $user,
		'user_queried' => $user_queried,
		'form_status'  => $form_status,
	]);
}
else
{
	echo $twig->render('error_404.html', []);
}
?>
