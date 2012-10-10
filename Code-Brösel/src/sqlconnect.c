#include "my_global.h" // Include this file first to avoid problems
#include "mysql.h" // MySQL Include File
#define SERVER11 "localhost"
#define USER1 "username"
#define PASSWORD1 "password"
#define DATABASE1 "databasename"

#define SERVER2 "localhost"
#define USER2 "username"
#define PASSWORD2 "password"
#define DATABASE2 "databasename"

int main()
{
    MYSQL *connect; 
    connect=mysql_init(NULL); // Initialisieren
    
    /* Initialisierung prüfen */
    if(!connect)   
    {
        fprintf(stderr,"MySQL Initialization Failed");
        return 1;
    }
 
    
    connect=mysql_real_connect(connect,SERVER1,USER1,PASSWORD1,DATABASE1,0,NULL,0);
    
    if(connect){
        printf("Connection Succeeded\n");
    }
    else{
        printf("Connection Failed!\n");
        
        /* Hier auf den anderen Server connecten! */
        connect=mysql_real_connect(connect,SERVER2,USER2,PASSWORD2,DATABASE2,0,NULL,0);

        
    }
    
    
    MYSQL_RES *res_set; /* Create a pointer to recieve the return value.*/
    MYSQL_ROW row;  /* Assign variable for rows. */
    mysql_query(connect,"SELECT * FROM TABLE");
    /* Send a query to the database. */
    unsigned int i = 0; /* Create a counter for the rows */
    
    res_set = mysql_store_result(connect);
    /* Receive the result and store it in res_set */
    
    unsigned int numrows = mysql_num_rows(res_set);
    /* Create the count to print all rows */
    
    
    /* This while is to print all rows and not just the first row found, */
    while ((row = mysql_fetch_row(res_set)) != NULL){
        printf("%s\n",row[i] != NULL ?
               row[i] : "NULL"); /* Print the row data */
    }
    mysql_close(connect);   /* Close and shutdown */
    return 0;
}