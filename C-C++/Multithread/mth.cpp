#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <sqlite3.h>
#include <string>

using namespace std;

#define NUM_THREADS 5

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

string sql[100];

static int set_str()
{
    for (int i = 0; i < 100; ++i)
    {
        sql[i] = ("INSERT OR REPLACE INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
                  "VALUES (" +
                  to_string(i + 1) + ", 'Paul " + to_string((i + 1) * 100) + "', 32, 'California', 20000.00 );");
        // cout << sql[i] << endl;
    }
    return 0;
}

string sql22 = "Select * from COMPANY";

string sql33 = "Select * from COMPANY";

static int insert()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sqll;

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        cout << "Can't open database: " << sqlite3_errmsg(db);
        return (0);
    }
    else
    {
        cout << "\nOpened database successfully" << endl;
    }

    /* Create SQL statement */

    /* Execute SQL statement */
    sqlite3_exec(db, "PRAGMA synchronous = OFF", NULL, NULL, &zErrMsg);
    sqlite3_exec(db, "PRAGMA journal_mode = MEMORY", NULL, NULL, &zErrMsg);
    sqlite3_exec(db, "PRAGMA journal_mode = wal", NULL, NULL, &zErrMsg);
    set_str();
    for (int i = 0; i < 100; i++)
    {
        sqll = const_cast<char *>(sql[i].c_str());
        cout << sql[i] << endl;
        rc = sqlite3_exec(db, sqll, callback, 0, &zErrMsg);
    }

    if (rc != SQLITE_OK)
    {
        cout << "\nSQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Action successfully" << endl;
    }
    sqlite3_close(db);
    return 0;
}

static int select()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sqll;

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        cout << "Can't open database: " << sqlite3_errmsg(db);
        return (0);
    }
    else
    {
        cout << "\nOpened database successfully" << endl;
    }

    /* Create SQL statement */

    /* Execute SQL statement */
    sqlite3_exec(db, "PRAGMA synchronous = OFF", NULL, NULL, &zErrMsg);
    sqlite3_exec(db, "PRAGMA journal_mode = MEMORY", NULL, NULL, &zErrMsg);
    sqlite3_exec(db, "PRAGMA journal_mode = wal", NULL, NULL, &zErrMsg);

    sqll = (char *)"Select * from COMPANY";
    rc = sqlite3_exec(db, sqll, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        cout << "\nSQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Action successfully" << endl;
    }
    sqlite3_close(db);
    return 0;
}

void *Hello1(void *)
{
    insert();
    time_t my_time = time(NULL);

    // ctime() used to give the present time
    cout << ctime(&my_time) << endl;
    pthread_exit(NULL);
}

void *Hello2(void *)
{
    select();
    time_t my_time = time(NULL);

    // ctime() used to give the present time
    printf("%s", ctime(&my_time));
    pthread_exit(NULL);
}

void *Hello3(void *)
{
    select();
    time_t my_time = time(NULL);

    // ctime() used to give the present time
    printf("%s", ctime(&my_time));
    pthread_exit(NULL);
}

int main()
{
    insert();
    pthread_t thread1;
    int rc;
    int i;

    rc = pthread_create(&thread1, NULL, Hello1, (void *)i);
    pthread_create(&thread1, NULL, Hello2, (void *)i);
    pthread_create(&thread1, NULL, Hello3, (void *)i);

    if (rc)
    {
        cout << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }
    pthread_exit(NULL);
    return 0;
}
