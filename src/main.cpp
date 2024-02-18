#include <string>
#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;

int main()
{
    cout << "2021-01-10T10:11:00 Epoch time: " << parseDateTimeToEpoch("2021-01-10T10:11:00") << endl;

    cout << "T10:30:00 Epoch time: " << parseDateTimeToEpoch("T10:30:00") << endl;

    cout << "2023-12-12 Epoch time: " << parseDateTimeToEpoch("2023-12-12") << endl;

    cout << "XXXX-12-12T10:08:00 Epoch time: " << parseDateTimeToEpoch("XXXX-12-12T10:08:00") << endl;

    cout << "2023-XX-12T10:11:00 Epoch time: " << parseDateTimeToEpoch("2023-XX-12T10:11:00") << endl;

    cout << "1970-1-XT00:00:00 Epoch time: " << parseDateTimeToEpoch("1970-1-XT00:00:00") << endl;

    cout << "2022-12-12T10:XX:00 Epoch time: " << parseDateTimeToEpoch("2022-12-12T10:XX:00") << endl;

    cout << "2022-12-12T10:XX:XX Epoch time: " << parseDateTimeToEpoch("2022-12-12T10:XX:XX") << endl;

    cout << "XXXX-12-12T10:XX:00 Epoch time: " << parseDateTimeToEpoch("XXXX-12-12T10:XX:00") << endl;

    cout << "XXXX-XX-XXTXX:XX:XX Epoch time: " << parseDateTimeToEpoch("XXXX-XX-XXTXX:XX:XX") << endl;

    cout << "XXXX-XX-XX Epoch time: " << parseDateTimeToEpoch("XXXX-XX-XX") << endl;

    cout << "TXX:XX:XX Epoch time: " << parseDateTimeToEpoch("TXX:XX:XX") << endl;

    return 0;
}