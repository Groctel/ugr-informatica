<?php
require_once("core.php");

class db_comment
{
	static function get ($id)
	{
		$mysqli = db_core::connect();

		$event = array(
			'id'        => '-1',
			'id_event'  => '-1',
			'id_author' => '-1',
			'date'      => '',
			'body'      => '',
			'edited'    => '',
		);

		if (db_core::is_cropped_md5($id))
		{
			$res = $mysqli->query(
				"SELECT *"            .
				"FROM   Comentarios " .
				"WHERE  id = '"   . $id . "'"
			);

			if ($res->num_rows > 0)
			{
				$row = $res->fetch_assoc();

				$event = array(
					'id'        => $row['id'],
					'id_event'  => $row['id_evento'],
					'id_author' => $row['id_autor'],
					'date'      => $row['fecha'],
					'body'      => $row['contenido'],
					'edited'    => $row['editado']
				);
			}
		}

		return $event;
	}

	static function get_from_event ($event_id)
	{
		$mysqli = db_core::connect();
		$table  = array();
		$index  = 0;

		$query = "SELECT DISTINCT Comentarios.*, Usuarios.* " .
			"FROM   Comentarios, Usuarios    " .
			"WHERE  Comentarios.id_evento = '" . $event_id . "' " .
			"AND    Comentarios.id_autor  = Usuarios.id";

		foreach ($mysqli->query($query) as $row)
			$table[$index++] = $row;

		return $table;
	}

	static function insert ($event_id, $user_id, $body)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"INSERT INTO Comentarios (id_evento, id_autor, fecha, contenido) " .
			"VALUES (" .
				"'"   . $event_id           . "'," .
				"'"   . $user_id            . "'," .
				"'"   . date("Y-m-d H:i:s") . "'," .
				"'"   . $body               . "'" .
			")"
		);
	}

	static function delete ($id)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"DELETE FROM Comentarios " .
			"WHERE  id = '" . $id . "'"
		);
	}

	static function update ($comment)
	{
		$mysqli = db_core::connect();

		echo "UPDATE Comentarios SET  " .
				"fecha     =     '" . date("Y-m-d H:i:s") . "'," .
				"contenido =     '" . $comment['body']    . "'," .
				"editado   = '1' " .
			"WHERE Comentarios.id = '" . $comment['id'] . "'";

		$mysqli->query(
			"UPDATE Comentarios SET  " .
				"fecha     =     '" . date("Y-m-d H:i:s") . "'," .
				"contenido =     '" . $comment['body']    . "'," .
				"editado   = '1' " .
			"WHERE Comentarios.id = '" . $comment['id'] . "'"
		);
	}
}
?>

