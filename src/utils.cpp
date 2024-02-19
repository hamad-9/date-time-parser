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

int daysInMonth(int month, int year)
{
    if (month == 2 && isLeapYear(year))
        return 29;
    return DAYS_PER_MONTH[month - 1];
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

// int daysSinceEpoch(int year, int month, int day)
// {
//     int leapYears = ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400) - ((EPOCH_START_YEAR - 1) / 4) + ((EPOCH_START_YEAR - 1) / 100) - ((EPOCH_START_YEAR - 1) / 400);

//     int totalDays = (year - EPOCH_START_YEAR) * 365 + leapYears;

//     for (int m = 1; m < month; m++) {
//         totalDays += daysInMonth(m, year);
//     }

//     totalDays += day - 1;

//     return totalDays;
// }


void quickSort(std::vector<DateTime> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(std::vector<DateTime> &arr, int low, int high)
{
    DateTime pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

long long dateTimeToEpoch(const DateTime &dateTime)
{
    int days = daysSinceEpoch(
        dateTime.getYear(),
        dateTime.getMonth(),
        dateTime.getDay());

    long long totalSeconds = days * SECONDS_PER_DAY + dateTime.getHour() * SECONDS_PER_HOUR + dateTime.getMinute() * SECONDS_PER_MINUTE + dateTime.getSecond();
    return totalSeconds;
}
