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
			echo ("Fallo al conectar: " . $mysqli->connect_error);

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
			'id'           => '0',
			'título'       => 'título',
			'organizador'  => 'organizador',
			'fecha'        => '01-01-1970',
			'descripción'  => 'descripción',
			'img1'         => 'img1',
			'img2'         => 'img2'
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
					'id'           => $row['id'],
					'título'       => $row['título'],
					'organizador'  => $row['organizador'],
					'fecha'        => $row['fecha'],
					'descripción'  => $row['descripción'],
					'img1'         => $row['img1'],
					'img2'         => $row['img2']
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

		$query = "SELECT * FROM Comentarios WHERE id_evento='" . $event_id . "'";

		foreach ($mysqli->query($query) as $row)
			$table[$index++] = $row;

		return $table;
	}
?>
