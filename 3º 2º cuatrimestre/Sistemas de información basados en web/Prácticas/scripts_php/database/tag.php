<?php
require_once("core.php");

class db_tag
{
	static function insert_tag_event_row ($id, $tag)
	{
		$mysqli = db_core::connect();

		$res = $mysqli->query(
			"SELECT name "    .
			"FROM   Tags "    .
			"WHERE  name = '" . $tag . "'"
		);

		if ($res->num_rows == 0)
			$mysqli->query(
				"INSERT INTO Tags (name)" .
				"VALUES ('" . $tag . "')"
			);

		$mysqli->query(
			"INSERT INTO HasTag (event_id, tag) " .
			"VALUES (" .
				"'" . $id  . "'," .
				"'" . $tag . "'"  .
			")"
		);
	}

	static function insert_tags ($tag_string, $event_id)
	{
		$tags = preg_split('/\s*,\s*/', $tag_string);

		foreach ($tags as $tag)
			db_tag::insert_tag_event_row($event_id, trim($tag));
	}

	static function get_from_event ($event_id)
	{
		$mysqli = db_core::connect();
		$tags   = array();
		$index  = 0;

		$query = "" .
			"SELECT tag "         .
			"FROM   HasTag "      .
			"WHERE  event_id = '" . $event_id . "' " .
			"ORDER BY tag";

		foreach ($mysqli->query($query) as $row)
			$tags[$index++] = $row['tag'];

		return $tags;
	}

	static function update ($event_id, $tags)
	{
		$mysqli = db_core::connect();

		$mysqli->query(
			"DELETE FROM HasTag " .
			"WHERE  event_id = '" . $event_id . "'"
		);

		db_tag::insert_tags($tags, $event_id);
	}
}
?>
