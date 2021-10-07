#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef struct student
{
    int age;
    string name;
} Student;

int main()
{
    std::queue<Student> q_data;
    q_data.push({18, "Cung"});
    q_data.push({19, "Dinh"});
    q_data.push({20, "Duy"});
    q_data.push({21, "Cung"});

    while (!q_data.empty())
    {
        cout << '\t' << q_data.front().age;
        cout << '\t' << q_data.front().name;
        q_data.pop();
    }
    cout << '\n';
}
