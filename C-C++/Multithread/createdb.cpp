#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        cout << azColName[i] << " : " << argv[i] ? argv[i] : "NULL";
    }
    cout << endl;
    return 0;
}

static int insert()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        cout << "Can't open database: " << sqlite3_errmsg(db);
        return (0);
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }

    /* Create SQL statement */
    sql = (char *)"INSERT OR REPLACE INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
                  "VALUES (1, 'Paul', 32, 'California', 20000.00 ); "
                  "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
                  "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "
                  "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
                  "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );"
                  "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
                  "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        cout << "SQL error: " << zErrMsg;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Table created successfully" << endl;
    }
    sqlite3_close(db);
    return 0;
}

int main(int argc, char *argv[])
{
    insert();
    return 0;
}