#include <cassert>
#include <iostream>
#include "utils.h"

void testDateTimeToEpoch() {
    // assert(parseDateTimeToEpoch("2021-01-10T10:11:00") == 1610273460);
    // assert(parseDateTimeToEpoch("T10:30:00") == 37800);
    // assert(parseDateTimeToEpoch("2023-12-12") == 1702339200);
}

void testLeapYear() {
    // assert(isLeapYear(2021) == false);
    // assert(isLeapYear(2020) == true);
    // assert(isLeapYear(2018) == false);
    // assert(isLeapYear(2024) == true);
}

int main() {
    testDateTimeToEpoch();
    testLeapYear();
    return 0;
}
