#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>

using namespace std;

// Throws runtime_error on error.
void changeNumberForID(const string& filename, int id, const string& newNumber);

int main()
{
    try {
        changeNumberForID("data.txt", 263, "415-555-3333");
    } catch (const exception& caughtException) {
        cerr << caughtException.what() << endl;
    }
    return 0;
}

void changeNumberForID(const string& filename, int id, const string& newNumber)
{
    ifstream inputData(filename);
    if (!inputData) {
        throw runtime_error("Error while opening file " + filename);
    }

    ostringstream tempData;
    int idRead;
    string number;
    bool idFound = false;

    while (inputData >> idRead >> number) {
        if (idRead == id) {
            tempData << idRead << " " << newNumber << " ";
            idFound = true;
        } else {
            tempData << idRead << " " << number << " ";
        }
    }

    inputData.close();

    if (!idFound) {
        throw runtime_error("ID not found in file " + filename);
    }

    ofstream outputData(filename);
    if (!outputData) {
        throw runtime_error("Error while opening file " + filename + " for writing");
    }

    outputData << tempData.str();
}
