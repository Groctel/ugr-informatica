<?php
require_once("core.php");

class db_user
{
	static function register ($name, $mail, $pass)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"INSERT INTO Usuarios (correo, nombre, pass)" .
			"VALUES (" .
				"'"     . $mail . "'," .
				"'"     . $name . "'," .
				"'"     . $pass . "'"  .
			")"
		);

		return db_user::login($mail, $pass);
	}

	static function get ($id)
	{
		$mysqli = db_core::connect();

		$data = array(
			'id'   => '-1',
			'mail' => '',
			'name' => '',
			'perm' => '',
		);

		$res = $mysqli->query(
			"SELECT id, correo, nombre, tipo " .
			"FROM   Usuarios " .
			"WHERE  id = '"    . $id . "'"
		);

		if ($res->num_rows > 0)
		{
			$row = $res->fetch_assoc();

			$data['id']   = $row['id'];
			$data['mail'] = $row['correo'];
			$data['name'] = $row['nombre'];
			$data['perm'] = $row['tipo'];
		}

		return $data;
	}

	static function login ($mail, $pass)
	{
		$mysqli = db_core::connect();
		$id     = '';

		$res = $mysqli->query(
			"SELECT id, pass  " .
			"FROM   Usuarios  " .
			"WHERE  correo = '" . $mail . "'"
		);

		if ($res->num_rows > 0)
		{
			$row = $res->fetch_assoc();

			if (password_verify($pass, $row['pass']))
				$id = $row['id'];
		}

		return $id;
	}

	static function mail_exists ($mail)
	{
		$mysqli = db_core::connect();

		$res = $mysqli->query(
			"SELECT *         " .
			"FROM   Usuarios  " .
			"WHERE  correo = '" . $mail . "'"
		);

		return ($res->num_rows > 0);
	}

	static function update_mail ($id, $mail)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"UPDATE Usuarios       " .
			"SET    correo      = '" . $mail . "'" .
			"WHERE  Usuarios.id = '" . $id   . "'"
		);
	}

	static function update_pass ($id, $pass)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"UPDATE Usuarios       " .
			"SET    pass        = '" . $pass . "'" .
			"WHERE  Usuarios.id = '" . $id   . "'"
		);
	}

	static function update_perm ($id, $perm)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"update Usuarios       " .
			"set    tipo        = '" . $perm . "'" .
			"where  Usuarios.id = '" . $id   . "'"
		);
	}

	static function perms_geq ($queried_perm, $required_perm)
	{
		$success = false;

		switch ($required_perm)
		{
			case 'everyone':
				if (!$success) $success = ($queried_perm == 'everyone');
			case 'moderator':
				if (!$success) $success = ($queried_perm == 'moderator');
			case 'manager':
				if (!$success) $success = ($queried_perm == 'manager');
			case 'superuser':
				if (!$success) $success = ($queried_perm == 'superuser');
		}

		return $success;
	}
}
?>
