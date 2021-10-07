#include <iostream>
#include "croncpp/include/croncpp.h"
#include <string.h>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

std::vector<std::string> split(std::string str, char delim)
{
    std::vector<std::string> out;
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
    return out;
}

std::string join(const std::vector<std::string> &v, std::string delimiter)
{

    std::string str_result = "";
    for (int i = 0; i < 5; i++)
    {
        str_result += v[i] + delimiter;
    }
    str_result += v[5];

    return str_result;
}

int cal_time(std::string str, std::string str1)
{
    size_t found = str.length() - 1 - str.find(str1);
    if (found != string::npos)
        cout << "Position is " << found << endl;

    return found;
}

int current_year;

int get_current_year()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    return 1900 + ltm->tm_year;
}

struct Date
{
    int d, m, y;
};

// To store number of days in
// all months from January to Dec.
const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

// This function counts number of
// leap years before the given date
int countLeapYears(Date d)
{
    int years = d.y;

    // Check if the current year needs to be
    //  considered for the count of leap years
    // or not
    if (d.m <= 2)
        years--;

    // An year is a leap year if it
    // is a multiple of 4,
    // multiple of 400 and not a
    // multiple of 100.
    return years / 4 - years / 100 + years / 400;
}

// This function returns number of
// days between two given dates
int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS
    // BEFORE FIRST DATE 'dt1'

    // initialize count using years and day
    long int n1 = dt1.y * 365 + dt1.d;

    // Add days for months in given date
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    // return difference between two counts
    return (n2 - n1);
}

Date timestamp = {1, 1, 2000};

int minute;
int day_of_week;
int day_of_month;
int month;
int year;

int main()
{
    std::string time_cron = "0 15 10 12,20 * 2 2021";
    auto cron = cron::make_cron(time_cron);
    cout << to_string(cron) << endl;
    std::vector<std::string> arrStr = split(time_cron, ' ');
    std::vector<std::string> arr_time;
    std::string yearStr;

    if (arrStr.size() >= 7)
    {
        yearStr = arrStr[6];
        cout << "year: " << yearStr << endl;
    }
    std::string new_time_cron = join(arrStr, " ");

    try
    {
        auto cron = cron::make_cron(new_time_cron);

        // for (auto e : split(to_string(cron), ' '))
        // {
        //     cout << e << endl;
        // }
        arr_time = split(to_string(cron), ' ');
        day_of_week = cal_time(arr_time[5], "1");
        day_of_month = cal_time(arr_time[3], "1");
        month = cal_time(arr_time[4], "1");
        minute = cal_time(arr_time[2], "1") * 60 + cal_time(arr_time[1], "1");

        cout << "-------------------------" << endl;
        cout << "minute:  " << minute << endl;
        cout << "day_of_month:   " << day_of_month << endl;
        cout << "day_of_week:  " << day_of_week << endl;
        year = atoi(yearStr.c_str());
        if (year == 0)
        {
            year = get_current_year();
        }

        cout << "year: " << year << endl;

        Date start_time = {day_of_month, month, year};
        cout << "Difference between two dates is " << getDifference(timestamp, start_time) << endl;
    }
    catch (cron::bad_cronexpr const &ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}