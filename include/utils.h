#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "DateTime.h" // Include the DateTime class definition

bool isLeapYear(int year);

int daysSinceEpoch(int year, int month, int day);

bool validDateTimeFormat(std::string &value);

bool undefined(std::string &value);

long long parseDateTimeToEpoch(const std::string &dateTime);

void quickSort(std::vector<DateTime>& arr, int low, int high);

int partition(std::vector<DateTime>& arr, int low, int high);

#endif // UTILS_H
