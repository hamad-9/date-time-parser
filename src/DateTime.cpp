#include <string>
#include <sstream>
#include "DateTime.h"

DateTime::DateTime(const std::string &dateTimeStr) : year(1970), month(1), day(1), hour(0), minute(0), second(0), originalString(dateTimeStr){
    parseDateTimeString(dateTimeStr);
}

bool DateTime::operator<(const DateTime &other) const {
    if (year != other.year)
        return year < other.year;
    if (month != other.month)
        return month < other.month;
    if (day != other.day)
        return day < other.day;
    if (hour != other.hour)
        return hour < other.hour;
    if (minute != other.minute)
        return minute < other.minute;
    return second < other.second; // Simplified for brevity
}

std::string DateTime::toString() const {
    return originalString;
}

void DateTime::parseDateTimeString(const std::string &dateTimeStr) {
    const char DateSeparator = '-';
    const char TimeSeparator = ':';
    const char TimeBegin = 'T';

    // Find 'T' to split date and time
    int tPos = dateTimeStr.find(TimeBegin);
    std::string datePart = dateTimeStr.substr(0, tPos);
    std::string timePart = tPos != std::string::npos ? dateTimeStr.substr(tPos + 1) : "";

    // Process date part
    size_t  firstDash = datePart.find(DateSeparator);
    size_t  secondDash = datePart.find(DateSeparator, firstDash + 1);
    if (firstDash != std::string::npos)
    {
        std::string yearStr = datePart.substr(0, firstDash);

        if (!undefined(yearStr))
        {
            year = stoi(yearStr);
        }

        if (secondDash != std::string::npos)
        {
            std::string monthStr = datePart.substr(firstDash + 1, secondDash - firstDash - 1);

            if (!undefined(monthStr))
            {
                month = stoi(monthStr);
            }

            std::string dayStr = datePart.substr(secondDash + 1);
            if (!undefined(dayStr))
            {
                day = stoi(dayStr);
            }
        }
    }

    // Process time part
    size_t firstColon = timePart.find(TimeSeparator);
    size_t secondColon = timePart.find(TimeSeparator, firstColon + 1);
    if (firstColon != std::string::npos)
    {
        std::string hourStr = timePart.substr(0, firstColon);
        if (!undefined(hourStr))
        {
            hour = stoi(hourStr);
        }

        if (secondColon != std::string::npos)
        {
            std::string minuteStr = timePart.substr(firstColon + 1, secondColon - firstColon - 1);
            if (!undefined(minuteStr))
            {
                minute = stoi(minuteStr);
            }

            std::string secondStr = timePart.substr(secondColon + 1);
            if (!undefined(secondStr))
            {
                second = stoi(secondStr);
            }
        }
    }
}

bool DateTime::undefined(std::string &value) {
    if (value.empty() || value == "X" || value == "XX" || value == "XXXX")
    {
        return true;
    }
    return false;
}
