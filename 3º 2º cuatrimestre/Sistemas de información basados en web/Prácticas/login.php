<?php
	ini_set('display_errors', 1);
	require_once "/usr/local/lib/php/vendor/autoload.php";
	include('scripts_php/database.php');

	$loader = new \Twig\Loader\FilesystemLoader('templates');
	$twig = new \Twig\Environment($loader);

	$mail      = '';
	$pass      = '';
	$form_used = false;

	if ($_SERVER['REQUEST_METHOD'] === 'POST')
	{
		$form_used = true;

		$mail = $_POST['mail'];
		$pass = $_POST['pass'];
		$id = login($mail, $pass);

		if (!empty($id))
		{
			session_start();
			$_SESSION['user_id'] = $id;

			header("Location: index.php");
			exit();
		}
	}

	echo $twig->render('login.html', [
		'mail'       => $mail,
		'form_used'  => $form_used,
	]);
?>
