<?php
	ini_set('display_errors', 1);
	require_once "./vendor/autoload.php";
	include('scripts_php/database.php');

	$loader = new \Twig\Loader\FilesystemLoader('templates');
	$twig   = new \Twig\Environment($loader);

	session_start();

	$user         = [];
	$user_queried = [];
	$valid_pass   = false;
	$form_used    = false;

	if (isset($_SESSION['user_id']))
		$user = user_data($_SESSION['user_id']);

	if (isset($_GET['account_id']))
		$user_queried = user_data($_GET['account_id']);
	else
		$user_queried = $user;

	if ($user_queried == $user)
	{
		$mail    = '';
		$newpass = '';
		$pass    = '';

		$valid_mail = true;
		$dupli_mail = false;

		if ($_SERVER['REQUEST_METHOD'] === 'POST')
		{
			$form_used = true;

			$mail    = $_POST['mail'];
			$newpass = $_POST['newpass'];
			$pass    = $_POST['pass'];
			$id      = login($user['mail'], $pass);

			if ($id == $user['id'])
			{
				$valid_pass = true;

				if (!empty($mail))
				{
					$valid_mail = is_mail($mail);
					$dupli_mail = mail_exists($mail);

					if ($valid_mail && !$dupli_mail)
						update_mail($user['id'], $mail);
				}

				if (!empty($newpass))
				{
					$newpass = password_hash($newpass, PASSWORD_BCRYPT);
					update_pass($user['id'], $newpass);
				}
			}
		}

		echo $twig->render('account.html', [
			'user'         => $user,
			'user_queried' => $user_queried,
			'form_used'    => $form_used,
			'valid_mail'   => $valid_mail,
			'dupli_mail'   => $dupli_mail,
			'valid_pass'   => $valid_pass,
		]);
	}
	else
	{
		if ($_SERVER['REQUEST_METHOD'] === 'POST')
		{
			$form_used = true;

			$pass = $_POST['pass'];
			$id   = login($user['mail'], $_POST['pass']);

			if ($id == $user['id'])
			{
				$valid_pass = true;
				update_perm($user_queried['id'], $_POST['perm']);
			}
		}

		echo $twig->render('account.html', [
			'user'         => $user,
			'user_queried' => $user_queried,
			'form_used'    => $form_used,
			'valid_pass'   => $valid_pass,
		]);
	}
?>
