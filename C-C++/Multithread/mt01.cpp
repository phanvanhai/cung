#include <iostream>
#include <cstdlib>
#include <time.h>
#include <pthread.h>
using namespace std;
#define THREAD_NUMBER 4

void *InLoiChao(void *)
{
    cout << "Hello World! " << endl;
    time_t my_time = time(NULL);

    // ctime() used to give the present time
    printf("%s", ctime(&my_time));
    pthread_exit(NULL);
}

void *Hello(void *)
{
    cout << "Hello Cung! " << endl;
    time_t my_time = time(NULL);

    // ctime() used to give the present time
    printf("%s", ctime(&my_time));
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1;
    int rc, rc1;
    rc = pthread_create(&thread1, NULL,
                        InLoiChao, (void *)thread1);

    rc1 = pthread_create(&thread1, NULL,
                         Hello, (void *)thread1);
    if (rc)
    {
        cout << "\nError: Khong the tao thread!" << rc << endl;
        exit(-1);
    }
    pthread_exit(NULL);
}