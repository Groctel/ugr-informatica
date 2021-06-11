<?php
require_once("core.php");

class db_comment
{
	static function get ($id)
	{
		$mysqli = db_core::connect();

		$event = array(
			'id'        => '',
			'id_event'  => '',
			'id_author' => '',
			'date'      => '',
			'body'      => '',
			'edited'    => '',
		);

		if (db_core::is_cropped_md5($id))
		{
			$res = $mysqli->query(
				"SELECT *"         .
				"FROM   Comments " .
				"WHERE  id = '"    . $id . "'"
			);

			if ($res->num_rows > 0)
			{
				$row = $res->fetch_assoc();

				$event = array(
					'id'        => $row['id'],
					'id_event'  => $row['id_event'],
					'id_author' => $row['id_author'],
					'date'      => $row['date'],
					'body'      => $row['body'],
					'edited'    => $row['edited']
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

		$query = "" .
			"SELECT DISTINCT Comments.*, Users.* " .
			"FROM     Comments, Users " .
			"WHERE    Comments.id_event  = '" . $event_id . "' " .
			"AND      Comments.id_author = Users.id " .
			"ORDER BY Comments.date DESC";

		foreach ($mysqli->query($query) as $row)
			$table[$index++] = $row;

		return $table;
	}

	static function insert ($event_id, $user_id, $body)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"INSERT INTO Comments (id_event, id_author, date, body) " .
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
			"DELETE FROM Comments " .
			"WHERE  id = '" . $id . "'"
		);
	}

	static function update ($comment)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"UPDATE Comments SET " .
				"date   = '" . date("Y-m-d H:i:s") . "'," .
				"body   = '" . $comment['body']    . "'," .
				"edited = 'TRUE' " .
			"WHERE Comments.id = '" . $comment['id'] . "'"
		);
	}
}
?>

