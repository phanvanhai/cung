import sqlite3
from sqlite3 import Error
import time


def create_connection(db_file):
    """ create a database connection to the SQLite database
        specified by the db_file
    :param db_file: database file
    :return: Connection object or None
    """
    conn = None
    try:
        conn = sqlite3.connect(db_file)
    except Error as e:
        print(e)

    return conn


def select_all_tasks(conn):
    """
    Query all rows in the tasks table
    :param conn: the Connection object
    :return:
    """
    cur = conn.cursor()
    # cur.execute("pragma table_info('albums');")
    # cur.execute("select * from pragma_table_info('albums');")
    cur.execute("pragma journal_mode = WAL;")
    cur.execute("pragma synchronous = normal;")
    cur.execute("pragma temp_store = memory;")
    cur.execute("pragma mmap_size = 30000000000;")
    for i in range(1, 10001):
        cur.execute("INSERT or REPLACE INTO Device(DeviceId, AppKey, NetKey) VALUES(" + str(i) +
                    ", 'Dinh Duy Cung " + str(i) + "', '" + str(i) + "');")

    rows = cur.fetchall()

    for row in rows:
        print(row)


# def select_task_by_priority(conn, priority):
#     """
#     Query tasks by priority
#     :param conn: the Connection object
#     :param priority:
#     :return:
#     """
#     cur = conn.cursor()
#     cur.execute("SELECT * FROM tasks WHERE priority=?", (priority,))

#     rows = cur.fetchall()

#     for row in rows:
#         print(row)


def main():
    database = r"rd1.Sqlite"

    # create a database connection
    conn = create_connection(database)
    with conn:
        # print("1. Query task by priority:")
        # select_task_by_priority(conn, 1)

        print("2. Query all tasks")
        select_all_tasks(conn)


if __name__ == '__main__':
    start = time.time()
    main()
    print(time.time() - start)
