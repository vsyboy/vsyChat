#include "my_global.h" 
#include "mysql.h" // MySQL Include 

#define SERVER1 "localhost"
#define USER1 "username"
#define PASSWORD1 "password"
#define DATABASE1 "databasename"

#define SERVER2 "localhost"
#define USER2 "username"
#define PASSWORD2 "password"
#define DATABASE2 "databasename"

int main()
{
    MYSQL *connect1;
    MYSQL *connect2;
    connect1=mysql_init(NULL); // Initialisieren
    connect2=mysql_init(NULL); // Initialisieren
    
    /* Initialisierung prüfen */
    if(!connect1 || !connect2)
    {
        fprintf(stderr,"MySQL Initialisierung auf mind. einer Instanz failed");
        return 1;
    }
 
    
    connect1=mysql_real_connect(connect1,SERVER1,USER1,PASSWORD1,DATABASE1,0,NULL,0);
    
    if(connect1){
        printf("Verbindung OK\n");
    }
    
    else{
        printf("Verbindung fehlgeschlagen!\n");
        
        /* Hier auf den anderen Server connecten! */
        connect2=mysql_real_connect(connect2,SERVER2,USER2,PASSWORD2,DATABASE2,0,NULL,0);
        
        
    }
    
    if (connect2){
        
        MYSQL_RES *res_set; /* Create a pointer to recieve the return value.*/
        MYSQL_ROW row;  /* Assign variable for rows. */
        mysql_query(connect2,"SELECT * FROM TABLE");
        /* Send a query to the database. */
        unsigned int i = 0; /* Create a counter for the rows */
        
        res_set = mysql_store_result(connect2);
        /* Receive the result and store it in res_set */
        
        unsigned int numrows = mysql_num_rows(res_set);
        /* Create the count to print all rows */
        
        
        /* This while is to print all rows and not just the first row found, */
        while ((row = mysql_fetch_row(res_set)) != NULL){
            printf("%s\n",row[i] != NULL ?
                   row[i] : "NULL"); /* Print the row data */
        }
        mysql_close(connect2);   /* Close and shutdown */

    }
    
    
    else if (connect1){
        
        MYSQL_RES *res_set; /* Create a pointer to recieve the return value.*/
        MYSQL_ROW row;  /* Assign variable for rows. */
        mysql_query(connect,"SELECT * FROM TABLE");
        /* Send a query to the database. */
        unsigned int i = 0; /* Create a counter for the rows */
        
        res_set = mysql_store_result(connect1);
        /* Receive the result and store it in res_set */
        
        unsigned int numrows = mysql_num_rows(res_set);
        /* Create the count to print all rows */
        
        
        /* This while is to print all rows and not just the first row found, */
        while ((row = mysql_fetch_row(res_set)) != NULL){
            printf("%s\n",row[i] != NULL ?
                   row[i] : "NULL"); /* Print the row data */
        }
        mysql_close(connect1);   /* Close and shutdown */

    }
    
    else {
        printf("Uh oh...");
    }
      return 0;
}