#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>


using namespace std;



int main() {
    ifstream inputFile("numbers.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    
    // Start timing
    auto start = chrono::high_resolution_clock::now();

    vector<int> codes;
    int code;
    while (inputFile >> code) {
        codes.push_back(code);
    }

    // End timing
    auto end = chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "vector input time: " << duration.count() << " milliseconds" << endl;



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/