#include <iostream>
#include <string>
#include <mysql.h>




int main() {

    std::string tables;
	MYSQL_RES *result;
	MYSQL_ROW row;
	MYSQL *connection, mysql;
	
	int state;
	
	mysql_init(&mysql);
	
	connection = mysql_real_connect(&mysql,"localhost","username","password","database",0,0,0);
	
	if (connection == NULL)
	{
		std::cout << mysql_error(&mysql) << std::endl;
		
		return 1;
	}
	
	state = mysql_query(connection, "SHOW TABLES");
	if (state !=0)
	{
		std::cout << mysql_error(connection) << std::endl;
		return 1;
	}
	
	result = mysql_store_result(connection);
	
	std::cout << "tables: " << mysql_num_rows(result) << std::endl;
	while ( ( row=mysql_fetch_row(result)) != NULL )
	{
	
	}
	
	mysql_free_result(result);
	
	mysql_close(connection);
    return 0;
}