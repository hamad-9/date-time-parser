#include <string>
#include <vector>
#include <iostream>
#include "utils.h"
#include "DateTime.h"
using namespace std;

const int SECONDS_PER_MINUTE = 60;
const int SECONDS_PER_HOUR = 3600;
const int SECONDS_PER_DAY = 86400;
const vector<int> DAYS_PER_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int DAYS_PER_YEAR = 365;
const int DAYS_PER_LEAP_YEAR = 366;

const int EPOCH_START_YEAR = 1970;
const int EPOCH_START_MONTH = 1;
const int EPOCH_START_DAY = 1;
const int EPOCH_START_HOUR = 0;
const int EPOCH_START_MINUTE = 0;
const int EPOCH_START_SECOND = 0;

const char TimeBegin = 'T';
const char DateSeparator = '-';
const char TimeSeparator = ':';

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysSinceEpoch(int year, int month, int day)
{
    int days = 0;

    for (int y = EPOCH_START_YEAR; y < year; ++y)
    {
        days += isLeapYear(y) ? DAYS_PER_LEAP_YEAR : DAYS_PER_YEAR;
    }

    for (int m = EPOCH_START_MONTH; m < month; ++m)
    {
        days += DAYS_PER_MONTH[m - 1];
        // Add 29 of Feb if it's exists
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
    int year = EPOCH_START_YEAR; 
    int month = EPOCH_START_MONTH; 
    int day = EPOCH_START_DAY;
    int hour = EPOCH_START_HOUR;
    int minute = EPOCH_START_MINUTE;
    int second = EPOCH_START_SECOND;

    // Find 'T' to split date and time
    int tPos = dateTime.find(TimeBegin);
    string datePart = dateTime.substr(0, tPos);
    string timePart = tPos != string::npos ? dateTime.substr(tPos + 1) : "";

    // Process date part
    int firstDash = datePart.find(DateSeparator);
    int secondDash = datePart.find(DateSeparator, firstDash + 1);

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
    int firstColon = timePart.find(TimeSeparator);
    int secondColon = timePart.find(TimeSeparator, firstColon + 1);

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

void quickSort(std::vector<DateTime>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(std::vector<DateTime>& arr, int low, int high) {
    DateTime pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
