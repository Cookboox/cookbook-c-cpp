#include <mysql.h>
#include <iostream>

using namespace std;

int qstate;

int main()
{

    MYSQL * conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "emeraldincubus", "testdb", 3306, NULL, 0);

    if (conn)
    {
        puts("Successful connection");
        string query = "SELECT * FROM test";
        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                printf("id: %s, Name: %s, Value: %s\n", row[0], row[1], row[2]);
            }
        }
        else
        {
            cout << "querry failed: " << mysql_error(conn) << endl;
        }
    }
    else
    {
        puts("connection to db has failed");
    }
         
    cin.get();
    return 0; 
}