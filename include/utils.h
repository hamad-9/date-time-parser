#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "DateTime.h"

bool isLeapYear(int year);

int daysSinceEpoch(int year, int month, int day);

void quickSort(std::vector<DateTime>& arr, int low, int high);

int partition(std::vector<DateTime>& arr, int low, int high);

long long dateTimeToEpoch(const DateTime& dateTime);

#endif // UTILS_H
