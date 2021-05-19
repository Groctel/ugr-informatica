<?php
ini_set('display_errors', 1);

require_once('vendor/autoload.php');
require('scripts_php/database/comment.php');
require('scripts_php/database/user.php');

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig   = new \Twig\Environment($loader);

session_start();

$form_used = false;

$user = db_user::get($_SESSION['user_id']);

if (db_user::perms_geq($user['perm'], 'moderator') && isset($_GET['comment_id']))
{
	$comment = db_comment::get($_GET['comment_id']);

	if ($_SERVER['REQUEST_METHOD'] === 'POST')
	{
		$form_used       = true;
		$comment['body'] = $_POST['body'];

		if (!empty($comment['body']))
		{
			db_comment::update($comment);
			header("Location: evento.php?event_id=". $comment['id_event']);
			exit();
		}
	}

	echo $twig->render('edit_comment.html', [
		'user'      => $user,
		'form_used' => $form_used,
		'comment'     => $comment,
	]);
}
else
{
	echo $twig->render('error_404.html', []);
}
?>
