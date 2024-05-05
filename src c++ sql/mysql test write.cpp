//Application programs should use this general outline for interacting with MySQL :
////Initialize the MySQL client library by calling mysql_library_init().
////Initialize a connection handler by calling mysql_init() and connect to the server by calling mysql_real_connect().
////Issue SQL statements and process their results. (The following discussion provides more information about how to do this.)
////Close the connection to the MySQL server by calling mysql_close().
////End use of the MySQL client library by calling mysql_library_end().

#include <mysql.h>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <fstream>

const char *server = "localhost";
const char *user = "root";
const char *password = "emeraldincubus";
const char *database = "trading";

int query_state;

void update_db()
{
    MYSQL *conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, NULL, CLIENT_MULTI_STATEMENTS);

    if (conn)
    {
        puts("Successful connection to update");
        query_state = mysql_query(conn, "set @csum := 0; update test set cum_sum = (@csum := @csum + volume) where cum_sum is null;");
        if (!query_state)
        {
            puts("Successful update a table");
        }
        else
            puts("Update table failed");
    }
    else
    {
        puts("No connection");
    }

    std::cin.get();

}





int main()
{      
    MYSQL *conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, NULL, 0);

    if (conn)
    { 
        puts("Successful connection to trading");
        query_state = mysql_query(conn, "CREATE TABLE test (cena float, trh varchar(10), volume int, cum_sum float)");
        if (!query_state)
        {
            puts("Successful creating a table");
        } else
            puts("Creating table failed"); 

       query_state = mysql_query(conn, "INSERT INTO test (cena, trh, volume) VALUES (32.3, 'NQ', 455)");
       if (!query_state)
       {
           puts("Successful insert into the table");
       } else
           puts("Inserting into table failed");
    }
    else
    {
         puts("No connection");
    }

    update_db();
    std::cin.get();
    
}





//int main()
//{
//    MYSQL *conn;
//    MYSQL_ROW row;
//    MYSQL_RES *res;
//
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, server, user, password, database, 0, NULL, 0);
//
//    if (conn)
//    {
//        puts("Successful connection to sc");
//        query_state = mysql_query(conn, "CREATE TABLE testing (cena float, trh varchar(10), volume int)");
//        if (!query_state)
//        {
//            puts("Successful creating a table");
//        }
//        else
//            puts("Creating table failed");
//
//        query_state = mysql_query(conn, "INSERT INTO testing (cena, trh, volume) VALUES (32.3, 'NQ', 455)");
//        if (!query_state)
//        {
//            puts("Successful insert into the table");
//        }
//        else
//            puts("Inserting into table failed");
//    }
//    else
//    {
//        puts("No connection");
//    }
//
//    std::cin.get();
//
//    return 0;
//}