#ifndef UTILS_H
#define UTILS_H

#include <string>

bool isLeapYear(int year);

int daysSinceEpoch(int year, int month, int day);

bool validDateTimeFormat(std::string &value);

bool undefinedShortPart(std::string &value);

bool undefinedLongPart(std::string &value);

long long parseDateTimeToEpoch(const std::string &dateTime);

#endif // UTILS_H
