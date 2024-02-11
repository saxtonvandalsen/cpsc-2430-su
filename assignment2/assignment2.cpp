// Saxton Van Dalsen
// assignment2.cpp
// 01/18/24

// Purpose: This program focuses on utilizing recursively implemented functions to
// various different problems. It incorporates a user interface to test and run 
// the various functions.

#include <iostream>
#include <string> // For string returning function
#include <cmath> // For ramanujan function calculation

using namespace std;

// Function prototypes
int mysterySequence(int n);
int tennisBalls(int height);
string decToBase2(int decNum);
bool isDivisibleBy7(int num);
double ramanujan(int depth, double nestedTerm);
void testFunctions();
void menu();

int main () {

    int choice;

    do {
        menu();
        cin >> choice;
        switch (choice) {

            case (1) :
                int n;
                cout << "Mystery Sequence. Please enter n to compute the nth number in sequence: " << endl;
                cin >> n;
                cout << "The " << n << "th number in mystery sequence is " << mysterySequence(n) << endl << endl;
                break;
            case (2) :
                int height;
                cout << "Tennis Balls. Please enter the height of the pyramid: " << endl;
                cin >> height;
                cout << "A pyramid with " << height << " levels hold " << tennisBalls(height) << " tennis balls." << endl << endl;
                break;
            case (3) :
                int decNum;
                cout << "Decimal to Binary equivalent. Please enter the decimal number to be converted: " << endl;
                cin >> decNum;
                cout << "The decimal number " << decNum << " is " << decToBase2(decNum) << " in binary." << endl << endl;
                break;
            case (4) :
                int num;
                cout << "Divisible by 7. Please enter a number to checked for divisibility by 7: " << endl;
                cin >> num;
                if (isDivisibleBy7(num)) {
                    cout << num << " is divisible by 7!" << endl << endl;
                } else {
                    cout << num << " is not divisible by 7." << endl << endl;
                }
                break;
            case (5) :
                int depth;
                cout << "Ramanujan. Enter integer depht: ";
                cin >> depth;
                cout << "Result at depth " << depth << ": " << ramanujan(depth, 0) << endl;
                break;
            case (6) :
                testFunctions();
                break;
            case (7) :
                break;
            default :
            break;
        }

    } while (choice != 7);

    return 0;
}

// Recursive function to return the nth member of the sequence
int mysterySequence(int n) {

    // Base cases
    if (n <= 0) {
        return 2;
    } else if (n == 1) {
        return 3;
    }
    // Recursively calling each (n - 1) and (n -2) and
    // then multiplying them to setup for the next term
    else {
        return mysterySequence(n - 1) * mysterySequence(n - 2);
    }
}

// Recursive function to return the number of tennis balls
// it contains based on the height
int tennisBalls(int height) {

    // Base cases
    if (height <= 0) {
        return 0;
    } else if (height == 1) {
        return 1;
    } 
    // Recursively calling height subtracted by 1 while
    // adding the height squared
    else {
        return tennisBalls(height - 1) + (height * height);
    }
}

// Recursive function to convert decimal number into binary
string decToBase2(int decNum) {

    // Base cases
    if (decNum <= 0) {
        return "0";
    } else if (decNum == 1) {
        return "1";
    } 
    // Recursively dividing by 2 to retrieve base 2 then
    // adding the remainder of the decimal number to the result
    else {
        return decToBase2(decNum / 2) + to_string(decNum % 2);
    }
}

// Recursive function to check if a number is divisible by 7
bool isDivisibleBy7(int num) {
    
    // Base case
    if (num == 0 || num == 7) {
        return true;
    }

    // Removing the last digit and doubling it
    int lastDigit = ((num % 10) * 2);

    // Subtracting the doubled last digit from the remaining number
    int remainingNumber = (num / 10) - lastDigit;

    // Recursively repeating if more than 2 digits are left
    if (remainingNumber >= 10) {
        return isDivisibleBy7(remainingNumber);
    }

    // Checking if the remaining 2-digit number is divisible by 7
    if (remainingNumber == 0 || remainingNumber % 7 == 0) {
        return true;
    } 

    // Otherwise, return false
    return false;
}

// Recursive function to calculate ramanujan nested radicals
double ramanujan(int depth, double depthCounter) {
    
    // Base case
    if (depth == depthCounter) {
        return (depth + 1) * sqrt(6 + depthCounter);
    } else {

    // Square root then recursively call the function while 
    // incremented depth counter
    return sqrt(6 + depthCounter + ramanujan(depth, depthCounter + 1));
    }
    // The value carried out to infinity equals 4
}

// Function to run all other functions with various inputs for testing
void testFunctions() {
    cout << "mysterySequence, n = 0: " << mysterySequence(0) << endl;
    cout << "mysterySequence, n = 1: " << mysterySequence(1) << endl;
    cout << "mysterySequence, n = 4: " << mysterySequence(4) << endl;
    cout << "mysterySequence, n = 7: " << mysterySequence(7) << endl;
    cout << "tennisBalls, height = 0: " << tennisBalls(0) << endl;
    cout << "tennisBalls, height = 1: " << tennisBalls(1) << endl;
    cout << "tennisBalls, height = 3: " << tennisBalls(3) << endl;
    cout << "tennisBalls, height = 10: " << tennisBalls(10) << endl;
    cout << "decToBase2, input = 0: " << decToBase2(0) << endl;
    cout << "decToBase2, input = 1: " << decToBase2(1) << endl;
    cout << "decToBase2, input = 13: " << decToBase2(13) << endl;
    cout << "decToBase2, input = 32: " << decToBase2(32) << endl;
    cout << "decToBase2, input = 321: " << decToBase2(321) << endl;
    cout << "isDivisibleBy7, input = 1: ";
    if(isDivisibleBy7(1)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "isDivisibleBy7, input = 7: ";
    if(isDivisibleBy7(7)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "isDivisibleBy7, input = 31: ";
    if(isDivisibleBy7(31)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "isDivisibleBy7, input = 1073: ";
    if(isDivisibleBy7(1073)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "isDivisibleBy7, input = 1729: ";
    if(isDivisibleBy7(1729)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "ramanujan, depth = 1: " << ramanujan(1, 0) << endl;
    cout << "ramanujan, depth = 3: " << ramanujan(3, 0) << endl;
    cout << "ramanujan, depth = 10: " << ramanujan(1, 0) << endl;
}

// Function to display menu of options for the user to choose from
void menu() {
    cout << "Welcome to the recursion assignment. What would you like to test?" << endl;
    cout << "1. mysterySequence" << endl;
    cout << "2. tennisBalls" << endl;
    cout << "3. decToBase2" << endl;
    cout << "4. isDivisibleBy7" << endl;
    cout << "5. ramanujan" << endl;
    cout << "6. run tests" << endl;
    cout << "7. Exit" << endl;
}