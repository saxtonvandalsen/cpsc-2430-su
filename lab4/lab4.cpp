// Saxton Van Dalsen
// lab4.cpp
// 02/07/2024

// Purpose: This program incorporates a Pet shelter system in the form of a
// MIN-HEAP priority queue. It provides a user interface to navigate through
// the different functions that are usable including inserting a Pet, adopting 
// a Pet and deleting a Pet. All while maintaining the MIN-HEAP property within
// the shelter and effectively releasing in allocated memory during the process.

#include <iostream>
#include <vector>
#include <string>
#include "PetHeap.h"

using namespace std;

// Function prototypes
void runTests();
void menu();

int main () {

    // Instance of PetHeap class
    PetHeap petShelter;

    // Used in case 2
    Pet* adoptedPet;

    // Used for user input in the menu
    int choice;
    string petName;
    int arrivalTime;

    do {

        menu();
        cin >> choice;

        switch (choice) {

            case (1) :
                // Asking user for the name for new Pet=
                cout << "What is the name of the pet: ";
                cin >> petName;

                // Asking user for arrival time for new Pet
                cout << "What is the arrival time: ";
                cin >> arrivalTime;
                petShelter.insertPet(petName, arrivalTime);
                break;
            case (2) :
                adoptedPet = petShelter.adoptOldestPet();
                if (adoptedPet != nullptr) {
                    cout << "Congratulation, you have adopted " << adoptedPet->name << ", arrival " << adoptedPet->arrival << endl;
                } else {
                    break;
                }
                break;
            case (3) :
                cout << "The shelter has " << petShelter.numPets() << " of pets." << endl;
                break;
            case (4) :
                petShelter.displayPets();
                break;
            case (5) :
                runTests();
                break;
            default :
                break;
        }

    } while (choice != 6);

    return 0;
}

// Menu function to display options for user interface
void menu() {
    cout << "Welcome to Lab 4 on Basic Heap Operation. What would you like to test?" << endl;
    cout << "1. Insert Pet" << endl;
    cout << "2. Adopt Pet" << endl;
    cout << "3. Number of Pets" << endl;
    cout << "4. Display Pets" << endl;
    cout << "5. Run tests" << endl;
    cout << "6. Exit" << endl;
}

// To run tests of all the functions of PetHeap class
void runTests() {

    // Instance of PetHeap class
    PetHeap testShelter;

    // For testing adoptions
    Pet* adoptedPet;

    // Inserting 10 pets (random arrival times)
    // for display purposes, same order below
    cout << "Inserting 10 pets:" << endl;
    cout << "Name: Rocco, Arrival: 8" << endl;
    cout << "Name: Jax, Arrival: 3" << endl;
    cout << "Name: TJ, Arrival: 4" << endl;
    cout << "Name: Buddy, Arrival: 1" << endl;
    cout << "Name: Gus, Arrival: 6" << endl;
    cout << "Name: Tiger, Arrival: 9" << endl;
    cout << "Name: Missy, Arrival: 7" << endl;
    cout << "Name: Scruffy, Arrival: 5" << endl;
    cout << "Name: Penelope, Arrival: 2" << endl;
    cout << "Name: Jade, Arrival: 10" << endl << endl;

    // 1. Inserting 10 pets with random arrival times and names
    testShelter.insertPet("Rocco", 8);
    testShelter.insertPet("Jax", 3);
    testShelter.insertPet("TJ", 4);
    testShelter.insertPet("Buddy", 1);
    testShelter.insertPet("Gus", 6);
    testShelter.insertPet("Tiger", 9);
    testShelter.insertPet("Missy", 7);
    testShelter.insertPet("Scruffy", 5);
    testShelter.insertPet("Penelope", 2);
    testShelter.insertPet("Jade", 10);


    // 2. Displaying the heap
    testShelter.displayPets();
    cout << endl;

    // 3. Adopting a few pets
    for (int i = 0; i < 3; i++) {
       adoptedPet = testShelter.adoptOldestPet();
        if (adoptedPet != nullptr) {
            cout << "Adopted Pet: " << adoptedPet->name << ", Arrival Time: " << adoptedPet->arrival << endl;
        } else {
            break;
        }
    }

    // 4. Display number of pets left
    cout << endl << "The shelter has " << testShelter.numPets() << " of pets left." << endl;
    cout << endl;

    // 5. Adopt all remaining pets
    for (int i = 0; i < 7; i++) {   
       adoptedPet = testShelter.adoptOldestPet();
        if (adoptedPet != nullptr) {
            cout << "Adopted Pet: " << adoptedPet->name << ", Arrival Time: " << adoptedPet->arrival << endl;
        } else {
            break;
        }
    }
    cout << endl << "Now attempting to adopt when no pets are available: " << endl;

    // 6. Attempting to adopt when no pets are available
    testShelter.adoptOldestPet();
}