<?php
class db_core
{
	static function connect ()
	{
		$mysqli = new mysqli(
			"localhost",
			"groctel",
			"*Q-OdKj5(Cqe2vlZ",
			"open_workshop"
		);

		if ($mysqli->connect_errno)
			echo("Fallo al conectar: " . $mysqli->connect_error);

		return $mysqli;
	}

	static function is_cropped_md5($event_id='')
	{
		return preg_match('/^[a-f0-9]{20}$/', $event_id);
	}

	static function is_mail ($mail)
	{
		return preg_match('/^.+@.+\..+$/', $mail);
	}
}
?>
