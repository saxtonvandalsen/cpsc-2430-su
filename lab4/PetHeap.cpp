// Saxton Van Dalsen
// PetHeap.cpp
// 02/07/2024

// Purpose: Implementation of member functions from PetHeap Class and
// Pet struct in the form of minimum heap property

#include "PetHeap.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Recursive function to percolate up by the given index for PetHeap (MinHeap)
void PetHeap::percolateUp(int index) {

    // Getting the parent for the given index
    int petParent = (index - 1) / 2;

    // Base case: If index equals zero/source or index
    // priority is greater than or equal to it's parent
    if (index == 0 || petHeap[index]->arrival >= petHeap[petParent]->arrival) {
        return;
    }

    // Checking if current index arrival priority is less 
    if (petHeap[index]->arrival < petHeap[petParent]->arrival) {
        
        // Swapping the current index with its parent
        swap(petHeap[index],petHeap[petParent]);

        // Recursively calling percolateUp from parent index
        percolateUp(petParent);
    }
}

// Recursive function to percolate down by the given index for PetHeap (minHeap)
void PetHeap::percolateDown(int index) {

    int leftChild = 2 * index + 1; // Get left child
    int rightChild = 2 * index + 2; // Get right child
    int sizeOfHeap = petHeap.size(); // Get size of heap
    int smallest = index; // For comparison and swapping indexes

    // Comparing left child with index and assigning as smallest if it's smaller
    // than current index
    if (leftChild < sizeOfHeap && petHeap[leftChild]->arrival < petHeap[smallest]->arrival) {
        smallest = leftChild;
    }
    // Comparing right child with index and assigning as smallest if it's smaller
    // than current index
    if (rightChild < sizeOfHeap && petHeap[rightChild]->arrival < petHeap[smallest]->arrival) {
        smallest = rightChild;
    }

    // Swapping current index with smallest if it doesn't equal smallest value
    // then recursively calling percolateDown
    if (smallest != index) {
        swap(petHeap[index], petHeap[smallest]);
        percolateDown(smallest);
    }

}

// Recursive function to percolate down and restore the heap property
// after replacing and deleting the root node from petHeap
void PetHeap::deleteMin() {

    // If petHeap is empty, return
    if (petHeap.empty()) {
        return;
    }

    // Getting the last element in petHeap
    Pet* lastPet = petHeap.back();

    // Replacing the root node with the last element
    // in petHeap
    swap(petHeap[0], lastPet);

    // Remove the last element from petHeap
    petHeap.pop_back();

    if (petHeap.empty()) {
        return;
    }

    // Percolate down until the minHeap property has
    // been restored
    percolateDown(0);
}

// Returns the minimum value of petHeap
Pet* PetHeap::peekMin() {
    return petHeap[0];
}

// Function to insert a new Pet at the end of petHeap
// then percolating up to restore minHeap property
void PetHeap::insertPet(string petName, int arrivalTime) {

    // Dynamically allocating a new Pet
    Pet* newPet = new Pet();
    newPet->name = petName; // Assigning it's given name
    newPet->arrival = arrivalTime; // Assigning it's given arrival time

    // Insert the new pet at the end of the vector
    petHeap.push_back(newPet);

    // Percolate up from the newly added Pet to restore the minHeap property
    percolateUp(petHeap.size() - 1);
}

// Getting the oldest pet that arrived in petHeap
// returning it then deleting it
Pet* PetHeap::adoptOldestPet() {

    // Returning if petHeap is empty
    if (petHeap.empty()) {
        cout << "There are no available pets to adopt." << endl;
        return nullptr;
    }

    // Getting the oldest Pet
    Pet* oldestPet = peekMin();

    // Removing the oldest Pet for adoption,
    // this will also restore the heap's property
    deleteMin();

    // Returning the oldest Pet
    return oldestPet;
}

// Funcion to return the amount of Pets in the
// petHeap shelter
int PetHeap::numPets() {

    // Check if petHeap is empty
    if (petHeap.empty()) {
        cout << "no pets in the heap currently." << endl;
    }

    return petHeap.size();
}

// Function to display each of the Pets in level order
// with their names and arrival order numbers
void PetHeap::displayPets() {

    // If petHeap is empty, return
    if (petHeap.empty()) {
        cout << "No pets in the heap currently." << endl;
        return;
    }

    // Get size of petHeap and store it in integer
    // for comparison purposes
    int sizeOfHeap = petHeap.size();

    cout << "The pets in the heap in level order: " << endl;

    // Creating a queue of Pet pointers and
    // pushing the first element in
    queue<Pet*> petQueue;
    petQueue.push(petHeap[0]);

    // Level order traverse through each element of petHeap
    for (int i = 0; i < sizeOfHeap; i++) {

        // Get the front element then dequeue it
        Pet* currentPet = petQueue.front();
        petQueue.pop();

        // Displaying the current Pet's name and arrival number
        cout << currentPet->name << " " << currentPet->arrival << ", ";
        
        // Getting the position of left and right chilren
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // Enqueue left child if it exists
        if (leftChild < sizeOfHeap) {
            petQueue.push(petHeap[leftChild]);
        }

        // Enqueue right child if it exists
        if (rightChild < sizeOfHeap) {
            petQueue.push(petHeap[rightChild]);
        }
    }
    cout << endl;
}
