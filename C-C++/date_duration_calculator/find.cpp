
// CPP program to demonstrate working of string
// find to search a string
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "0000000000000100000100000000000";
    string str1 = "1";

    // Find first occurrence of "geeks"
    size_t found = str.find(str1);
    if (found != string::npos)
        cout << "First occurrence is " << found << endl;

    // Find next occurrence of "geeks". Note here we pass
    // "geeks" as C style string.
    char arr[] = "1";
    found = str.find(arr, found + 1);
    if (found != string::npos)
        cout << "Next occurrence is " << found << endl;

    return 0;
}