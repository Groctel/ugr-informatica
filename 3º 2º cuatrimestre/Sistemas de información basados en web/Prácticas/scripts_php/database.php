<?php
	function connect ()
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

	function is_cropped_md5($event_id='')
	{
		return preg_match('/^[a-f0-9]{20}$/', $event_id);
	}

	function event_row ($event_id)
	{
		$mysqli = connect();

		$event = array(
			'id'     => '0',
			'title'  => 'title',
			'id_org' => 'id_org',
			'date'   => '01-01-1970',
			'desc'   => 'desc',
			'img1'   => 'img1',
			'img2'   => 'img2'
		);

		if (is_cropped_md5($event_id))
		{
			$res = $mysqli->query(
				"SELECT *" .
				"FROM Eventos " .
				"WHERE id='" . $event_id . "'"
			);

			if ($res->num_rows > 0)
			{
				$row = $res->fetch_assoc();

				$event = array(
					'id'     => $row['id'],
					'title'  => $row['título'],
					'id_org' => $row['id_org'],
					'date'   => $row['fecha'],
					'desc'   => $row['descripción'],
					'img1'   => $row['img1'],
					'img2'   => $row['img2']
				);
			}
		}

		return $event;
	}

	function event_table ()
	{
		$mysqli = connect();
		$table  = array();
		$index  = 0;

		foreach ($mysqli->query("SELECT id, título, img1 FROM Eventos") as $row)
			$table[$index++] = $row;

		return $table;
	}

	function comment_table ($event_id)
	{
		$mysqli = connect();
		$table  = array();
		$index  = 0;

		$query = "SELECT DISTINCT Comentarios.id, Comentarios.fecha, Comentarios.contenido, Usuarios.nombre, Usuarios.correo " .
			"FROM   Comentarios, Usuarios " .
			"WHERE  Comentarios.id_evento='" . $event_id . "' " .
			"AND    Comentarios.id_autor = Usuarios.id";


		foreach ($mysqli->query($query) as $row)
			$table[$index++] = $row;

		return $table;
	}

	function register_user ($name, $mail, $pass)
	{
		$mysqli = connect();

		$mysqli->query(
			"INSERT INTO Usuarios (id, correo, nombre, pass, tipo)" .
			"VALUES (" .
				"''," .
				"'"   . $mail . "'," .
				"'"   . $name . "'," .
				"'"   . $pass . "'," .
				"'everyone'"  .
			")"
		);

		$id = "";

		$res = $mysqli->query(
			"SELECT id " .
			"FROM Usuarios " .
			"WHERE correo='" . $mail . "'"
		);

		if ($res->num_rows > 0)
		{
			$row = $res->fetch_assoc();
			$id  = $row['id'];
		}

		return $id;
	}

	function is_mail ($mail)
	{
		return preg_match('/^.+@.+\..+$/', $mail);
	}

	function mail_exists ($mail)
	{
		$mysqli = connect();

		$res = $mysqli->query(
			"SELECT * " .
			"FROM Usuarios " .
			"WHERE correo='" . $mail . "'"
		);

		return ($res->num_rows > 0);
	}

	function login ($mail, $pass)
	{
		$mysqli = connect();
		$id     = '';

		$res = $mysqli->query(
			"SELECT id, pass " .
			"FROM Usuarios " .
			"WHERE correo='" . $mail . "'"
		);

		if ($res->num_rows > 0)
		{
			$row = $res->fetch_assoc();

			if (password_verify($pass, $row['pass']))
				$id = $row['id'];
		}

		return $id;
	}

	function user_data ($id)
	{
		$mysqli = connect();

		$data = array(
			'id'   => $id,
			'mail' => '_',
			'name' => '_',
			'perm' => 'everyone',
		);

		$res = $mysqli->query(
			"SELECT id, correo, nombre, tipo " .
			"FROM Usuarios " .
			"WHERE id='" . $id . "'"
		);

		if ($res->num_rows > 0)
		{
			$row  = $res->fetch_assoc();
			$data = array(
				'id'   => $row['id'],
				'mail' => $row['correo'],
				'name' => $row['nombre'],
				'perm' => $row['tipo']
			);
		}

		return $data;
	}

	function update_mail ($id, $mail)
	{
		$mysqli = connect();

		$mysqli->query(
			"UPDATE Usuarios "      .
			"SET correo = '"        . $mail . "'" .
			"WHERE Usuarios.id = '" . $id   . "'"
		);
	}

	function update_pass ($id, $pass)
	{
		$mysqli = connect();

		$mysqli->query(
			"UPDATE Usuarios "      .
			"SET pass = '"          . $pass . "'" .
			"WHERE Usuarios.id = '" . $id   . "'"
		);
	}

	function update_perm ($id, $perm)
	{
		$mysqli = connect();

		$mysqli->query(
			"update usuarios "      .
			"set tipo = '"          . $perm . "'" .
			"where usuarios.id = '" . $id   . "'"
		);
	}

	function create_event ($id, $title, $date, $desc, $img1, $img2)
	{
		$mysqli = connect();

		$mysqli->query(
			"INSERT INTO Eventos (id, título, id_org, fecha, descripción, img1, img2)" .
			"VALUES (" .
				"''," .
				"'"   . $title . "'," .
				"'"   . $id    . "'," .
				"'"   . $date  . "'," .
				"'"   . $desc  . "'," .
				"'"   . $img1  . "'," .
				"'"   . $img2  . "'"  .
			")"
		);

		$event_id = "";

		$res = $mysqli->query(
			"SELECT id " .
			"FROM Eventos " .
			"WHERE título='" . $title . "' AND fecha='" . $date . "'"
		);

		if ($res->num_rows > 0)
		{
			$row = $res->fetch_assoc();
			$event_id  = $row['id'];
		}

		return $event_id;
	}

	function update_event ($id, $title, $date, $desc, $img1, $img2)
	{
		$mysqli = connect();

		$mysqli->query(
			"UPDATE Eventos SET" .
				"título='"      . $title . "'," .
				"fecha="        . $date  . ","  .
				"descripción='" . $desc  . "'," .
				"img1='"        . $img1  . "'," .
				"img2='"        . $img2  . "'"  .
			"WHERE Eventos.id = '" . $id   . "'"
		);
	}

	function delete_event ($id)
	{
		$mysqli = connect();

		$mysqli->query(
			"DELETE FROM Eventos " .
			"WHERE Eventos.id = '" . $id   . "'"
		);
	}

	function add_comment ($id, $user_id, $comment)
	{
		$mysqli = connect();

		$mysqli->query(
			"INSERT INTO Comentarios (id_evento, id_autor, fecha, contenido) " .
			"VALUES (" .
				"'"   . $id . "'," .
				"'"   . $user_id . "'," .
				"'"   . date("Y-m-d H:i:s") . "'," .
				"'"   . $comment . "'" .
			")"
		);
	}

	function delete_comment ($id)
	{
		$mysqli = connect();

		$mysqli->query(
			"DELETE FROM Comentarios " .
			"WHERE id='" . $id . "'"
		);
	}
?>
