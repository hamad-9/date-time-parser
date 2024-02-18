#include <string>
#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;

const int SECONDS_PER_MINUTE = 60;
const int SECONDS_PER_HOUR = 3600;
const int SECONDS_PER_DAY = 86400;
const vector<int> DAYS_PER_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysSinceEpoch(int year, int month, int day)
{
    int days = 0;

    for (int y = 1970; y < year; ++y)
    {
        days += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < month; ++m)
    {
        days += DAYS_PER_MONTH[m - 1];
        if (m == 2 && isLeapYear(year))
        {
            days += 1;
        }
    }

    days += day - 1;
    return days;
}

bool validDateTimeFormat(string &value)
{
    return true;
}

bool undefined(string &value)
{
    if (value.empty() || value == "X" || value == "XX" || value == "XXXX")
    {
        return true;
    }
    return false;
}

long long parseDateTimeToEpoch(const string &dateTime)
{
    int year = 1970, month = 1, day = 1, hour = 0, minute = 0, second = 0;

    // Find 'T' to split date and time
    int tPos = dateTime.find('T');
    string datePart = dateTime.substr(0, tPos);
    string timePart = tPos != string::npos ? dateTime.substr(tPos + 1) : "";

    // Process date part
    int firstDash = datePart.find('-');
    int secondDash = datePart.find('-', firstDash + 1);

    if (firstDash != string::npos)
    {
        string yearStr = datePart.substr(0, firstDash);

        if (!undefined(yearStr))
        {
            year = stoi(yearStr);
        }

        if (secondDash != string::npos)
        {
            string monthStr = datePart.substr(firstDash + 1, secondDash - firstDash - 1);

            if (!undefined(monthStr))
            {
                month = stoi(monthStr);
            }

            string dayStr = datePart.substr(secondDash + 1);
            if (!undefined(dayStr))
            {
                day = stoi(dayStr);
            }
        }
    }

    // Process time part
    int firstColon = timePart.find(':');
    int secondColon = timePart.find(':', firstColon + 1);

    if (firstColon != string::npos)
    {
        string hourStr = timePart.substr(0, firstColon);
        if (!undefined(hourStr))
        {
            hour = stoi(hourStr);
        }

        if (secondColon != string::npos)
        {
            string minuteStr = timePart.substr(firstColon + 1, secondColon - firstColon - 1);
            if (!undefined(minuteStr))
            {
                minute = stoi(minuteStr);
            }

            string secondStr = timePart.substr(secondColon + 1);
            if (!undefined(secondStr))
            {
                second = stoi(secondStr);
            }
        }
    }

    int days = daysSinceEpoch(year, month, day);

    long long totalSeconds = days * SECONDS_PER_DAY + hour * SECONDS_PER_HOUR + minute * SECONDS_PER_MINUTE + second;

    return totalSeconds;
}
