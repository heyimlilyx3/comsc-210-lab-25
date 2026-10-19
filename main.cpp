#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <list>
#include <set>
#include <string>
#include <iomanip>

using namespace std;



int main() {
    ifstream inputFile("codes.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    // Start timing
    auto start = chrono::steady_clock::now();

    vector<string> codes;
    string code;
    while (inputFile >> code) {
        codes.push_back(code);
    }

    // End timing
    auto end = chrono::steady_clock::now();

    // Calculate duration
    auto duration = chrono::duration<double, milli>(end - start);
    cout << fixed << setprecision(3);
    cout << "vector input time: " << duration.count() << " milliseconds" << endl;

    inputFile.close();

    // Input into list
    ifstream inputFileList("codes.txt");
    if (!inputFileList) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Start timing
    start = chrono::steady_clock::now();

    list<string> codeList;
    while (inputFileList >> code) {
        codeList.push_back(code);
    }

    // End timing
    end = chrono::steady_clock::now();

    // Calculate duration
    duration = chrono::duration<double, milli>(end - start);
    cout << "list input time: " << duration.count() << " milliseconds" << endl;

    inputFileList.close();

    // Input into set
    ifstream inputFileSet("codes.txt");
    if (!inputFileSet) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Start timing
    start = chrono::steady_clock::now();

    set<string> codeSet;
    while (inputFileSet >> code) {
        codeSet.insert(code);
    }

    // End timing
    end = chrono::steady_clock::now();

    // Calculate duration
    duration = chrono::duration<double, milli>(end - start);
    cout << "set input time: " << duration.count() << " milliseconds" << endl;

    inputFileSet.close();


    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/