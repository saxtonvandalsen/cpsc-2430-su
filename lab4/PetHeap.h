// Saxton Van Dalsen
// PetHeap.h
// 02/07/2024

// Purpose: Declaration of struct Pet and PetHeap (minHeap) Class

#include <vector>
#include <string>

using namespace std;

struct Pet {
    string name;
    int arrival;
    };

class PetHeap {
    private:
        vector<Pet*> petHeap;
        void percolateUp(int index);
        void percolateDown(int index);
        void deleteMin();
        Pet* peekMin();
    public:
        PetHeap(){
            // Creating an empty vector of pointers to Pet
            // objects and assigning to petHeap
            petHeap = vector<Pet*>();
        }
        // Destructor for memory dealloaction
        ~PetHeap() {
            for (Pet* pet : petHeap) {
                delete pet;
            }
        }
        void insertPet(string petName, int arrivalTime);
        Pet* adoptOldestPet();
        int numPets();
        void displayPets();
};