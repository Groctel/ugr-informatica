<?php
require_once("core.php");

class db_event
{
	static function delete ($id)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"DELETE FROM Eventos  " .
			"WHERE  Eventos.id = '" . $id   . "'"
		);
	}

	static function insert ($event, $id_org)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"INSERT INTO Eventos (título, id_org, fecha, descripción, img1, img2)" .
			"VALUES (" .
				"'"   . $event['title'] . "'," .
				"'"   . $id_org         . "'," .
				"'"   . $event['date']  . "'," .
				"'"   . $event['desc']  . "'," .
				"'"   . $event['img1']  . "'," .
				"'"   . $event['img2']  . "'"  .
			")"
		);

		$event_id = "";

		$res = $mysqli->query(
			"SELECT id        " .
			"FROM   Eventos   " .
			"WHERE  título = '" . $event['title'] . "'" .
			"AND    fecha  = '" . $event['date']  . "'"
		);

		if ($res->num_rows > 0)
		{
			$row      = $res->fetch_assoc();
			$event_id = $row['id'];
		}

		return $event_id;
	}

	static function update ($event)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"UPDATE Eventos SET  " .
				"título      =   '" . $event['title'] . "'," .
				"fecha       =   '" . $event['date']  . "'," .
				"descripción =   '" . $event['desc']  . "'," .
				"img1        =   '" . $event['img1']  . "'," .
				"img2        =   '" . $event['img2']  . "'"  .
			"WHERE Eventos.id = '" . $event['id']    . "'"
		);
	}

	static function get ($event_id)
	{
		$mysqli = db_core::connect();

		$event = array(
			'id'     => '-1',
			'title'  => '',
			'id_org' => '',
			'date'   => '',
			'desc'   => '',
			'img1'   => '',
			'img2'   => ''
		);

		if (db_core::is_cropped_md5($event_id))
		{
			$res = $mysqli->query(
				"SELECT *"        .
				"FROM   Eventos " .
				"WHERE  id = '"   . $event_id . "'"
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

	static function event_table ()
	{
		$mysqli = db_core::connect();
		$table  = array();
		$index  = 0;

		foreach ($mysqli->query("SELECT id, título, img1 FROM Eventos") as $row)
			$table[$index++] = $row;

		return $table;
	}
}
?>
