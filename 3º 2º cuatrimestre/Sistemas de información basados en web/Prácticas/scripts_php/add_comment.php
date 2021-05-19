<?php
ini_set('display_errors', 1);

require_once('../vendor/autoload.php');
require("database/comment.php");
require("database/user.php");

$loader = new \Twig\Loader\FilesystemLoader('../templates');
$twig   = new \Twig\Environment($loader);

session_start();

if (isset($_GET['event_id']))
{
	$event_id = $_GET['event_id'];

	if (isset($_SESSION['user_id']))
	{
		$user = db_user::get($_SESSION['user_id']);

		if (db_user::perms_geq($user['perm'], 'everyone'))
		{
			if (isset($_POST['comment']))
			{
				$comment = $_POST['comment'];
				db_comment::insert($event_id, $user['id'], $comment);
			}
		}
	}

	header("Location: ../evento.php?event_id=" . $event_id);
	exit();
}

echo $twig->render('error_404.html', []);
?>
