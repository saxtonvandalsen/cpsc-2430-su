// Saxton Van Dalsen
// assignment1.cpp or hw1.cpp
// 01/11/24

// Purpose: This program incorporates an Animal Shelter Promotion System. Allows 
// the user to add and adopt animals from the shelter incorporating dynamic memory 
// allocation and deallocation. User can navigate through a menu of options that
// display these functionalities.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Class to represent information of a Pet
class Pet {
    public:
        string name;            // Name of the pet
        string category;        // Category; (Cat or Dog)
        int arrivalOrder;       // To track arrival order of the pets into the animal shelter

        // Constructor to initialize a Pet's characteristics
        Pet(string n, string c) {
            name = n;
            category = c;
            arrivalOrder = 0;
        }
};

// Class to manage Animal Shelter Promotion System
class AnimalShelterSystem {
    private:
        queue<Pet*> catQueue;   // Queue for cats
        queue<Pet*> dogQueue;   // Queue for dogs
        string name;            // To store the name of the pet given by user input
        int arrivalOrder;       // To assign arrival time for newly added pets
        
    public:
        // Function to add an animal to the system
        void addAnimal(string category) {

            cout << "Please enter the " << category << "'s name: " << endl;
            cin >> name;

            // Creating a new pet and assigning its name and arrival order number
            Pet* newAnimal = new Pet(name, category);
            newAnimal->arrivalOrder = arrivalOrder++;
            
            // Setting the category of the new cat and adding it to catQueue
            if (category == "CAT") {
                newAnimal->category = "cat";
                catQueue.push(newAnimal);
            }
            
            // Setting the category of the new dog and adding it to dogQueue
            if (category == "DOG") {
                newAnimal->category = "dog";
                dogQueue.push(newAnimal);
            }
        }
        
        // Function to get an animal from the system based on the adoption policy
        Pet* getAnimal(string category) {

            // Check if adopter wants to adopt a cat, extracts oldest cat "based on arrival time"
            if (category == "CAT" && !catQueue.empty()) {
                Pet* frontCat = catQueue.front();
                catQueue.pop();
                return frontCat;
            }
            // Check if adopter wants to adopt a dog, extracts oldest dog "based on arrival time"
            else if (category == "DOG" && !dogQueue.empty()) {
                Pet* frontDog = dogQueue.front();
                dogQueue.pop();
                return frontDog;
            } 
            // If adopter has no preference, extract oldest pet "based on arrival time"
            else if (category == "ANY") {
                // First check if both queues are not empty
                if (!catQueue.empty() && !dogQueue.empty()) {
                    // Returning the pet that is the oldest "based on arrival time"
                    return (catQueue.front()->arrivalOrder < dogQueue.front()->arrivalOrder)
                    ? getAnimal("CAT") : getAnimal("DOG");
            } 
            // Checking if only the catQueue is not empty
            else if (!catQueue.empty()) {
                Pet* oldestCat = catQueue.front();
                catQueue.pop();
                return oldestCat;
            } 
            // Checking if only the dogQueue is not empty
            else if (!dogQueue.empty()) {
                Pet* oldestDog = dogQueue.front();
                dogQueue.pop();
                return oldestDog;
            } else {
            return nullptr;
        }
    }
    // Return nullptr if there are no animals to adopt
    return nullptr;
}

        // Destructor to deallocate rest of memory from each queue when user quits
        ~AnimalShelterSystem() {
            // Deallocating memory of all pets from the catQueue
            while (!catQueue.empty()) {
                delete catQueue.front();
                catQueue.pop();
            }

            // Deallocating memory of all pets from the dogQueue
            while(!dogQueue.empty()) {
                delete dogQueue.front();
                dogQueue.pop();
            }
        }
};

void menu();

// Main function
int main () {

    // Instance of AnimalShelterSystem class for adoption facility functions in the menu
    AnimalShelterSystem newAnimalShelter;

    int choice;
    do {
        menu();
        cin >> choice;
        
        switch (choice) {
            case (1) : {
                newAnimalShelter.addAnimal("CAT");
                break;
            }
            case (2) : {
                newAnimalShelter.addAnimal("DOG");
                break;
            }
            case (3) : {
                Pet* adoptedCat = newAnimalShelter.getAnimal("CAT");
                if (adoptedCat != nullptr) {
                    cout << "Congrats on adopting a cat, their name is: " << adoptedCat->name << endl;
                    delete adoptedCat;
                } else {
                    cout << "Sorry, no cats are available for adoption today" << endl;
                }
                break;
            }
            case (4) : {
                Pet* adoptedDog = newAnimalShelter.getAnimal("DOG");
                if (adoptedDog != nullptr) {
                    cout << "Congrats on adopting a dog, their name is: " << adoptedDog->name << endl;
                    delete adoptedDog;
                } else {
                    cout << "Sorry, no dogs are avaiable for adoption today" << endl;
                }
                break;
            }
            case (5) : {
                Pet* adoptedAnyAnimal = newAnimalShelter.getAnimal("ANY");
                if (adoptedAnyAnimal != nullptr) {
                    cout << "Congrats on adopting a " << adoptedAnyAnimal->category << ", their name is: " << 
                    adoptedAnyAnimal->name << endl;
                    delete adoptedAnyAnimal;
                } else {
                    cout << "Sorry, no animals are avaiable for adoption today" << endl;
                }
                break;
            }
            case (6) : {
                break;
            }
        }

    } while (choice != 6);

    return 0;
}

// Function to display information for user options to choose from
void menu() {
    cout << "Welcome to the animal shelter. What would you like to do?" << endl;
    cout << "1. Add a CAT to the shelter" << endl;
    cout << "2. Add a DOG to the shelter" << endl;
    cout << "3. Adopt a CAT from the shelter" << endl;
    cout << "4. Adopt a DOG from the shelter" << endl;
    cout << "5. Adopt any animal from the shelter " << endl;
    cout << "6. Exit" << endl;
}