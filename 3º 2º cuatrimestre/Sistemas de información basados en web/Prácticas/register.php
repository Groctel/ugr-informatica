<?php
	ini_set('display_errors', 1);
	require_once "/usr/local/lib/php/vendor/autoload.php";
	include('scripts_php/database.php');

	$loader = new \Twig\Loader\FilesystemLoader('templates');
	$twig = new \Twig\Environment($loader);

	$user = '';
	$mail = '';
	$pass = '';

	$valid_mail = false;
	$dupli_mail = false;
	$valid_pass = false;
	$form_used  = false;

	if ($_SERVER['REQUEST_METHOD'] === 'POST')
	{
		$form_used = true;

		$user = $_POST['user'];
		$mail = $_POST['mail'];
		$pass = $_POST['pass'];

		if (!empty($mail))
		{
			$valid_mail = is_mail($mail);
			$dupli_mail = mail_exists($mail);
		}

		$valid_pass = !empty($pass);

		if (!empty($user) && $valid_mail && !$dupli_mail && $valid_pass)
		{
			$pass = password_hash($pass, PASSWORD_BCRYPT);
			$id   = register_user($user, $mail, $pass);

			echo $id;

			session_start();
			$_SESSION['user_id'] = $id;

			header("Location: index.php");
			exit();
		}
	}

	echo $twig->render('register.html', [
		'user'       => $user,
		'mail'       => $mail,
		'form_used'  => $form_used,
		'valid_mail' => $valid_mail,
		'dupli_mail' => $dupli_mail,
		'valid_pass' => $valid_pass,
	]);
?>
