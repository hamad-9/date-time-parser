#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>

class DateTime {


private:
    int year, month, day, hour, minute, second;
    std::string originalString;
    void parseDateTimeString(const std::string& dateTimeStr);
    bool undefined(std::string &value);

public:
    DateTime(const std::string& dateTimeStr);
    bool operator <(const DateTime& other) const;
    std::string toString() const;

    // Getter methods
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
};

#endif // DATE_TIME_H
