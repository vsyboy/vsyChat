<?

// Einfacher SQL Connect zum Server mit Status
// Auf Webserver ausführen

$ok = 1;
$dbuser="USERNAME	"; 		// DB Benutzername
$dbpass="*******	"; 		// DB Passwort
$dbname="DBNAME		"; 		// DB Name

$chandle = @mysql_connect("localhost", $dbuser, $dbpass) 
or die ('<html><strong>SQL:</strong> SQL Connection "'.$dbname.'" im Eimer!<br /></html>');


if ($ok == 0)
	{
		echo '';
	}


else if ($ok == 1) 
	{
		echo '<html><strong>SQL:</strong> SQL Connection OK!<br /></html>';
 	}



?>