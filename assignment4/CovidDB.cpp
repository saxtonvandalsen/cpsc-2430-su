// Saxton Van Dalsen
// CovidDB.cpp
// 02/18/2024

// Purpose: Implementation of the hash table and data entry 
// functions from the header file 'CovidDB.h'.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "CovidDB.h"

using namespace std;

// Function to parse a date in the format of 'M/D/YY' and return
// a date object
Date parseDate(const string& date) {
    int month;
    int day;
    int year;
    char slash;

    // Initializing an iss object to then read and
    // evaluate the date given while handling slashes
    istringstream iss(date);
    iss >> month >> slash >> day >> slash >> year;

    // Return the appropriate date
    return Date(month, day, year);
}

// Function to compare two dates, to be used while inserting
// Covid data into the hash table
bool compareDates(const Date& date1, const Date& date2) {
    
    // Comparing the years
    if (date1.year != date2.year) {
        return date1.year < date2.year;
    }
    // If years are the same then compare months
    if (date1.month != date2.month) {
        return date1.month < date2.month;
    }
    // If months are the same then compare the days
    return date1.day < date2.day;
}

// Hash function to convert the "key (country)" and returns an
// integer value computed to a specific loaction in the hash table
int CovidDB::hash(const string& country) {

    int sum = 0; // To return sum
    int m = 17; // m is size of hash table
    int i = 1; // Index value starting at 1

    // Iterating through each character in the string
    // for each character 'c' at position 'i' in string country
    for (char c : country) {
            sum = ((i+1) * c); // Accumulating the sum
            i++; // Increment for the next character value
    }

    return sum % m; // Using modulus to ensure it's within hash table bounds
}

// Function to insert a DataEntry into the hash table. Returns true
// if record is added, false otherwise
bool CovidDB::add(DataEntry* entry) {
   
    // Hash the country name to determine the index
    int index = hash(entry->getCountry());

    // Access the vector at the determined index
    vector<DataEntry*>& entries = hashTable[index];

    // Check if the entry already exists in the hash table
    for (DataEntry* data : entries) {

        // Find the country that's already in the hash table
        if (data->getCountry() == entry->getCountry()) {

            // Get the dates from each DataEntry object
            string date1 = data->getDate();
            string date2 = entry->getDate();

            // Parse the current date and the given entry date
            Date currentDate = parseDate(date1);
            Date newDate = parseDate(date2);

            // Comparing the dates, if 
            // (new entry date < current date), return false
            if (compareDates(currentDate, newDate)) {
                data->setDate(entry->getDate());
                data->setCases(entry->getCases());
                data->setDeaths(entry->getDeaths());
                return true;
            } else {
                return false;
            }
        }
    }

    // Entry doesn't exist, add it to the hash table
    hashTable[index].push_back(entry);
    return true;
}

// Retrieves a DataEntry by a given specific country name,
// returns nullptr is given country doesn't exist in the hash table
DataEntry* CovidDB::get(string country) {

    // Hashing the given 'country' to retrieve
    // it's index value
    int index = hash(country);

    // Accessing DataEntry contents based
    // on the specific index in the hash table
    vector<DataEntry*> entries = hashTable[index];

    // Traversing through the vector at the specific index
    for (DataEntry* data : entries) {

        // Comparing country names to find the match
        if (data->getCountry() == country) {
            cout << "Date: " << data->getDate() << ", ";
            cout << "Country: " << data->getCountry() << ", ";
            cout << "Cases: " << data->getCases() << ", ";
            cout << "Deaths: " << data->getDeaths() << endl;
            return data; // Return if there's a match
        }
    }

    // Display message if country was not found
    cout << "Country not found." << endl;

    // If no match, return nullptr
    return nullptr;
}

// Removes a DataEntry from the hash table based on the given
// specific country name, if it exists in the hash table
void CovidDB::remove(string country) {

    // Hashing the given 'country' to retrive
    // it's index value
    int index = hash(country);

    // Accessing DataEntry contents based
    // on the specific index in the hash table
    vector<DataEntry*>& entries = hashTable[index];

    // Traversing through the vector with an iterator
    for (auto i = entries.begin(); i != entries.end();) {

        // Comparing each country to the given country
        if ((*i)->getCountry() == country) {
            delete *i; // Delete iterator/object pointing to the element
            i = entries.erase(i); // Erase the element using the iterator
            return; // No need to continue traversing
        } else {
            i++; // Move to the next element
        }
    }

    // Display message if the country was not in the hash table
    cout << country << " is not in the hash table" << endl;
}

// Displays the contents of the hash table
void CovidDB::displayTable() {

    // Traversing the hash table
    for (auto& bucket : hashTable) {

        // Accessing the DataEntry's in the current bucket
        for (DataEntry* entry : bucket) {
            cout << entry->getDate();
            cout << ", " << entry->getCountry();
            cout << ", " << entry->getCases();
            cout << ", " << entry->getDeaths() << endl << endl;
        }
    }
}

// Get a DataEntry's country
string DataEntry::getCountry() const {
    return country;
}

// Get a DataEntry's country
string DataEntry::getDate() const {
    return date;
}

// Get cumulative cases
int DataEntry::getCases() const {
    return c_cases;
}

// Get cumulative deaths
int DataEntry::getDeaths() const {
    return c_deaths;
}

// Set the date for data entry
void DataEntry::setDate(string setDate) {
        date = setDate;
}

// Set the country for data entry
void DataEntry::setCountry(string setCountry) {
    country = setCountry;
}

// Set the cases for data entry
void DataEntry::setCases(int setCases) {
    c_cases += setCases;
}

// Set the deaths for data entry
void DataEntry::setDeaths(int setDeaths) {
    c_deaths += setDeaths;
}
