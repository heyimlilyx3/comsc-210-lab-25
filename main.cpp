#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream>
#include <list>
#include <set>
#include <string>
#include <iomanip>
#include <iterator>

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

    // Now for sorting

    // vector sort
    start = chrono::steady_clock::now();
    sort(codes.begin(), codes.end());
    end = chrono::steady_clock::now();
    cout << "vector sort time: " << chrono::duration<double, milli>(end - start).count() << " milliseconds" << endl;

    // list sort
    start = chrono::steady_clock::now();
    codeList.sort();
    end = chrono::steady_clock::now();
    cout << "list sort time: " << chrono::duration<double, milli>(end - start).count() << " milliseconds" << endl;

    // set sort (not needed, as set is always sorted)
    cout << "set sort time: -1 milliseconds (set is always sorted)" << endl;

    // Inserting

    // vector insert
    start = chrono::steady_clock::now();
    codes.insert(codes.begin() + codes.size() / 2, "TESTCODE");
    end = chrono::steady_clock::now();
    cout << "vector insert time: " << chrono::duration<double, milli>(end - start).count() << " milliseconds" << endl;

    // list insert
    start = chrono::steady_clock::now();
    codeList.insert(next(codeList.begin(), codeList.size() / 2), "TESTCODE");
    end = chrono::steady_clock::now();
    cout << "list insert time: " << chrono::duration<double, milli>(end - start).count() << " milliseconds" << endl;

    // set insert
    start = chrono::steady_clock::now();
    codeSet.insert("TESTCODE");
    end = chrono::steady_clock::now();
    cout << "set insert time: " << chrono::duration<double, milli>(end - start).count() << " milliseconds" << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/