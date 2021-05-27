<?php
ini_set('display_errors', 1);

require_once('database/core.php');

$mysqli = db_core::connect();
$result = '';
$query  = $_POST['query'];

$res = $mysqli->query(
	"SELECT * " .
	"FROM   Events " .
	"WHERE  title LIKE '%" . $query . "%'"
);


if ($res->num_rows > 0)
{
	while ($row = $res->fetch_assoc())
	{
		$link = '<a href="evento.php?event_id=' . $row['id'] . '">' . $row['title'] . '</a><br>';
		$link = preg_replace("/(" . $query . ")/i", "<span class='hl'>$1</span>", $link);
		$result .= $link;
	}
}

echo $result;
?>

