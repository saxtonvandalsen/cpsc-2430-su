// Saxton Van Dalsen
// main.cpp
// 02/18/2024

// Purpose: This is the main file for the implemenation of a Covid Data Tracker
// in the form of a hash table. It utilizes hash table operations to read and 
// store WHO Covid-19 data into a hash table for efficent inserting, retrieving,
// deleting, and displaying of Covid data. Providing a menu of options and user 
// interface to navigate through it's different funcitonalities.

#include <iostream>
#include <vector>
#include <string>
#include "CovidDB.h"
#include <fstream>
#include <sstream>

using namespace std;

// Function prototypes
void menu();

int main () {

    CovidDB hashTable; // Instance of CovidDB

    // For user interface
    int choice;
    string date;
    string country;
    int cases;
    int deaths;

    // Declaring an input file stream and opening
    // the covid .csv file
    fstream inFile;
    inFile.open("WHO-COVID-data.csv");
    string line;

    // Read and ignore first line in file
    getline(inFile, line);
    line = "";
    string tempString; // Used for integer conversion

    stringstream inputString(line);

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1 :

                // Get data from every line after the first line
                while(getline(inFile, line)) {
                    inputString.clear();
                    inputString.str(line);

                    getline(inputString, date, ',');
                    getline(inputString, country, ',');
                    getline(inputString, tempString, ',');
                    cases = atoi(tempString.c_str());
                    getline(inputString, tempString, ',');
                    deaths = atoi(tempString.c_str());

                    hashTable.add(new DataEntry(date, country, cases, deaths));

                    line = "";
                }
                break;
            case 2 :
                cout << "Enter a date: ";
                cin >> date;
                cin.ignore();
                cout << "Enter a country: ";
                getline(cin, country);
                cout << "Enter the cases: ";
                cin >> cases;
                cout << "Enter the deaths: ";
                cin >> deaths;

                hashTable.add(new DataEntry(date, country, cases, deaths));
                cout << endl;
                break;
            case 3 :
                cin.ignore();
                cout << "Enter a country name to retrieve data: ";
                getline(cin, country);

                hashTable.get(country);
                break;
            case 4 :
                cin.ignore();
                cout << "Enter a country name to remove: ";
                getline(cin, country);

                hashTable.remove(country);
                break;
            case 5 :
                hashTable.displayTable();
                break;
            default :
                break;
        }
    } while (choice != 0);

    return 0;
}

// Menu function to display options for user choice
void menu() {
    cout << "Covid Tracker" << endl;
    cout << "Please choose the operation you want: " << endl;
    cout << "1. Create the initial hash table" << endl;
    cout << "2. Add a new data entry" << endl;
    cout << "3. Get a data entry" << endl;
    cout << "4. Remove a data entry" << endl;
    cout << "5. Display hash table" << endl;
    cout << "0. Quit the system" << endl;
}