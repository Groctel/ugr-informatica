<?php
require_once("core.php");
require_once("tag.php");

class db_event
{
	static function delete ($id)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"DELETE FROM Events  " .
			"WHERE  Events.id = '" . $id . "'"
		);
	}

	static function insert ($event, $id_org)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"INSERT INTO Events (title, id_org, date, body, img1, img2, hidden)" .
			"VALUES (" .
				"'"     . $event['title']   . "'," .
				"'"     . $id_org           . "'," .
				"'"     . $event['date']    . "'," .
				"'"     . $event['body']    . "'," .
				"'"     . $event['img1']    . "'," .
				"'"     . $event['img2']    . "'," .
				"'"     . $event['hidden']  . "'"  .
			")"
		);

		$event_id = "";

		$res = $mysqli->query(
			"SELECT id "       .
			"FROM   Events   " .
			"WHERE  title = '" . $event['title'] . "'" .
			"AND    date  = '" . $event['date']  . "'"
		);

		if ($res->num_rows > 0)
		{
			$row      = $res->fetch_assoc();
			$event_id = $row['id'];
			db_tag::insert_tags($event['tags'], $event_id);
		}

		return $event_id;
	}

	static function update ($event, $tags)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"UPDATE Events SET " .
				"title  = '" . $event['title']  . "'," .
				"date   = '" . $event['date']   . "'," .
				"body   = '" . $event['body']   . "'," .
				"hidden = '" . $event['hidden'] . "'," .
				"img1   = '" . $event['img1']   . "'," .
				"img2   = '" . $event['img2']   . "'"  .
			"WHERE Events.id = '" . $event['id'] . "'"
		);

		db_tag::update($event['id'], $tags);
	}

	static function get ($event_id)
	{
		$mysqli = db_core::connect();

		$event = array(
			'id'     => '',
			'title'  => '',
			'id_org' => '',
			'date'   => '',
			'body'   => '',
			'hidden' => '',
			'img1'   => '',
			'img2'   => '',
		);

		if (db_core::is_cropped_md5($event_id))
		{
			$res = $mysqli->query(
				"SELECT * "      .
				"FROM   Events " .
				"WHERE  id = '"  . $event_id . "'"
			);

			if ($res->num_rows > 0)
			{
				$row = $res->fetch_assoc();

				$event = array(
					'id'     => $row['id'],
					'title'  => $row['title'],
					'id_org' => $row['id_org'],
					'date'   => $row['date'],
					'body'   => $row['body'],
					'hidden' => $row['hidden'],
					'img1'   => $row['img1'],
					'img2'   => $row['img2']
				);
			}
		}

		return $event;
	}

	static function event_table ()
	{
		$mysqli = db_core::connect();
		$table  = array();
		$index  = 0;

		$res = $mysqli->query(
			"SELECT   id, title, img1 " .
			"FROM     Events "  .
			"WHERE    Events.date > '" . date("Y-m-d H:i:s") . "' " .
			"AND      Events.hidden = '0'" .
			"ORDER BY date"
		);

		foreach ($res as $row)
			$table[$index++] = $row;

		return $table;
	}
}
?>
