#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include "utils.h"
using namespace std;


const string INPUT_FILE = "input.txt";
const string OUTPUT_FILE = "output.txt";



int main() {

    ifstream inputFile(INPUT_FILE);
    if (!inputFile.is_open()) {
        cerr << "Failed to open input file '" << INPUT_FILE << "'." << endl;
        return 1;
    }

    ofstream outputFile(OUTPUT_FILE);
    if (!outputFile.is_open()) {
        cerr << "Failed to open output file '" << OUTPUT_FILE << "'." << endl;
        return 1;
    }

    vector<pair<long long, string>> dateTimeEpochPairs;
    string line;

    while (getline(inputFile, line)) {
        long long epochTime = parseDateTimeToEpoch(line);
        dateTimeEpochPairs.emplace_back(epochTime, line);
    }

    // Sort by epoch time
    sort(dateTimeEpochPairs.begin(), dateTimeEpochPairs.end());

    for (const auto &pair : dateTimeEpochPairs) {
        outputFile << pair.second << " Epoch time: " << pair.first << endl;
    }

    inputFile.close();
    outputFile.close();

    cout<<"Finished Successfully"<<endl;

    return 0;
}
