#include <fstream>
#include <iostream>
#include <vector>
#include "DateTime.h"
#include "utils.h"

const std::string INPUT_FILE = "input.txt";
const std::string OUTPUT_FILE = "output.txt";

int main() {
    std::ifstream inputFile(INPUT_FILE);
    std::ofstream outputFile(OUTPUT_FILE);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::vector<DateTime> dateTimes;
    std::string line;

    while (getline(inputFile, line)) {
        DateTime dt(line);
        dateTimes.push_back(dt);
    }

    quickSort(dateTimes, 0, dateTimes.size() - 1);

    for (const auto& dt : dateTimes) {
        std::cout<<"pio pio"<<dt.toString()<<std::endl;
        
        long long epochTime = dateTimeToEpoch(dt);
        outputFile << dt.toString() << " Epoch time: " << epochTime << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Finished Successfully" << std::endl;

    return 0;
}
