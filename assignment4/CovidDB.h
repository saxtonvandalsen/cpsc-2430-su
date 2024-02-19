// Saxton Van Dalsen
// CovidDB.h
// 02/18/2024

// Purpose: Declaration of the classes DataEntry, CovidDB and struct Date. DataEntry class
// is used to handle all incoming Covid data. CovidDB class is used to handle all
// hashing functionalities for the hash table implementation for the Covid Data. Date
// is used to compare two dates for correct inserting into in the hash table.

#ifndef CovidDB_H
#define CovidDB_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Used to break down and compare dates in chronological order
struct Date {
    int month;
    int day;
    int year;

    // Constructor to initialize the date accordingly
    Date (int m, int d, int y) : month(m), day(d), year(y) {}

    Date parseDate(const string& date);
    bool compareDates(const Date& date1, const Date& date2);
};

// Class to handle and maintain covid data entries
class DataEntry {
    private:
        string date;
        string country;
        int c_cases;
        int c_deaths;
    public:
    // constructor, optional getters and setters
    DataEntry(string date, string country, int cases, int deaths) :
    date(date), country(country), c_cases(cases), c_deaths(deaths) {}

    // Getter functions for data entries
    string getDate() const;
    string getCountry() const;
    int getCases() const;
    int getDeaths() const;

    // Setter functions for data entries
    void setDate(string setDate);
    void setCountry(string setCountry);
    void setCases(int setCases);
    void setDeaths(int setDeaths);
};

// Class to handle hash table and its functions
class CovidDB {
    private:
        // Hash table holding pointers to DataEntry
        // objects using vectors of vectors for
        // separate chaining to resolve collisions
        vector<vector<DataEntry*> > hashTable;

        int size = 17; // m = 17
    public:
        // Inline initialize hashTable's outside vector
        // with size 17 through the constructor
        CovidDB() : hashTable(17) {}

        int hash(const string& country);
        bool add(DataEntry* entry);
        DataEntry* get(string country);
        void remove(string country);
        void displayTable();
};

#endif