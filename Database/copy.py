import sqlite3
from sqlite3 import Error
import time
from threading import Thread
import threading

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


def select_all_tasks():
    database = r"rd1.Sqlite"

    # create a database connection
    conn = create_connection(database)
    """
    Query all rows in the tasks table
    :param conn: the Connection object
    :return:
    """
    cur = conn.cursor()
    # cur.execute("pragma table_info('albums');")
    # cur.execute("select * from pragma_table_info('albums');")
    # cur.execute("PRAGMA journal_mode = WAL;")
    # cur.execute("PRAGMA synchronous = normal;")
    # cur.execute("PRAGMA temp_store = memory;")
    # cur.execute("PRAGMA mmap_size = 30000000000;")
    cur.execute("Select * FROM Device")

    rows = cur.fetchall()

    for row in rows:
        print("Thread 1 - \n")
        print(row)


def select_task_by_priority():
    database = r"rd1.Sqlite"

    # create a database connection
    conn = create_connection(database)
    """
    Query all rows in the tasks table
    :param conn: the Connection object
    :return:
    """
    cur = conn.cursor()
    # cur.execute("pragma table_info('albums');")
    # cur.execute("select * from pragma_table_info('albums');")
    # cur.execute("PRAGMA journal_mode = WAL;")
    # cur.execute("PRAGMA synchronous = normal;")
    # cur.execute("PRAGMA temp_store = memory;")
    # cur.execute("PRAGMA mmap_size = 30000000000;")
    cur.execute("Select * FROM Device")

    rows = cur.fetchall()

    for row in rows:
        print("xxxxxxxxxxxxxxxxxxxxx\n")
        print(row)


def main():
    # with conn:
        # print("1. Query task by priority:")
        # select_task_by_priority(conn, 1)

        # print("2. Query all tasks")
        # select_all_tasks(conn)

        # t = time.time()
    t1 = threading.Thread(target=select_all_tasks, args=())
    t2 = threading.Thread(target=select_task_by_priority, args=())
    t1.start()
    t2.start()
    t1.join()
    t2.join()


if __name__ == '__main__':
    start = time.time()
    main()
    print(sqlite3.threadsafety)
    print(time.time() - start)
