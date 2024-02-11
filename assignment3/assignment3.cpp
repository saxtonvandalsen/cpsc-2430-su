// Saxton Van Dalsen
// assignment3.cpp
// 01/30/2023

// Purpose: this program is to manage a binary search tree (BST) representing a shelter of pets. 
// It facilitates the addition, deletion, and retrieval of pet records based on their names. 
// The binary search tree structure allows for efficient organization and retrieval of pet data, supporting operations 
// such as searching for a specific pet, adding new pets, and removing pets from the shelter. The program adheres to the 
// properties of a binary search tree to maintain a well-structured and easily managable data organization for efficient 
// pet management in the shelter.

#include "ShelterBST.h"
#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void menu();
void test();

int main () {

    ShelterBST tree; // ShelterBST instance

    int choice; // For user input

    do {
        menu();
        cin >> choice;
        string name;

        switch (choice) {
            case (1) :
                // Insert 10 pets for testing of each of the functions
                // outside of the last function that tests all of them itself
                tree.insertPet("Rocco", 3);
                tree.insertPet("Jade", 9);
                tree.insertPet("Gus", 13);
                tree.insertPet("Sterling", 1);
                tree.insertPet("Bubba", 7);
                tree.insertPet("Link", 8);
                tree.insertPet("Gandy", 5);
                tree.insertPet("Missy", 11);
                tree.insertPet("Penelope", 6);
                tree.insertPet("Jack", 4);
                cout << "10 pets inserted. Now testing inserting a duplicate value: (Duplicate checking message below)" << endl;
                tree.insertPet("Link", 8);
                cout << endl;
                break;
            case (2) :
                cout << "Enter Pet's name to search for: " << endl;
                cin >> name;
                tree.searchPet(name);
                cout << endl;
                break;
            case (3) :
                cout << "Enter a Pet's name to delete: ";
                cin >> name;
                tree.deleteNode(tree.getRoot(), name);
                cout << "Pet " << name << " has been removed from the Shelter" << endl;
                break;
            case (4) :
                tree.inorderDisplay();
                cout << endl;
                break;
            case (5) :
                tree.preorderDisplay();
                cout << endl;
                break;
            case (6) :
                tree.postorderDisplay();
                cout << endl;
                break;
            case (7) :
                cout << "Enter a Pet's name to check there parent: ";
                cin >> name;
                tree.displayParent(name);
                cout << endl;
                break;
            case (8) :
                cout << "Enter a Pet's name to check there predecessor: ";
                cin >> name;
                tree.displayPredecessor(name);
                cout << endl;
                break;
            case (9) :
                cout << "Total number of nodes in the tree is: " 
                << tree.totalNodes(tree.getRoot()) << endl << endl;
                break;
            case (10) :
                cout << "Total number of internal nodes in the tree is: " 
                << tree.internalNodes(tree.getRoot()) << endl << endl;
                break;
            case (11) :
                cout << "Total number of nodes in the tree at level 1 is : " << 
                tree.levelNodes(tree.getRoot(), 1) << endl << endl;
                break;
            case (12) :
                cout << "The height of the tree is: " << tree.height(tree.getRoot()) << endl << endl;
                break;
            case (13) :
                if (tree.isBalanced(tree.getRoot())) {
                    cout << "True, tree is balanced." << endl << endl;
                } else {
                    cout << "False, tree is not balanced." << endl << endl;
                }
                break;
            case (14) :
                tree.destroyTree(tree.getRoot());
                cout << endl;
                break;
            case (15) :
                cout << endl;
                test();
                break;
            default :
                break;
        }
    } while (choice != 0);

    return 0;
}

// Menu function to display options for user to choose from
void menu() {
cout << "Welcome to my implementation of ShelterBST" << endl;
cout << "Please choose the operation you want:" << endl;
cout << "1. Insert a node" << endl;
cout << "2. Search a value" << endl;
cout << "3. Delete a node " << endl;
cout << "4. InOrder traversal of ShelterBST" << endl;
cout << "5. PreOrder traversal of ShelterBST" << endl;
cout << "6. PostOrder traversal of ShelterBST" << endl;
cout << "7. Find parent node" << endl;
cout << "8. Find predecessor" << endl;
cout << "9. Number of nodes in the tree" << endl;
cout << "10. Number of internal nodes in the tree" << endl;
cout << "11. Number of nodes at given level" << endl;
cout << "12. Find the height of the tree" << endl;
cout << "13. Check if tree is balanced" << endl;
cout << "14. Destroy the tree" << endl;
cout << "15. Test all functions" << endl;
cout << "0. Quit the system" << endl;
}

// To test all functions
void test() {

    ShelterBST tree; // ShelterBST instance

    cout << "Inserting 10 pets into the Shelter: " << endl;
    cout << "Rocco, age 3" << endl;
    cout << "Jade, age 9" << endl;
    cout << "Gus, age 13" << endl;
    cout << "Sterling, age 1" << endl;
    cout << "Bubba, age 7" << endl;
    cout << "Link, age 8" << endl;
    cout << "Gandy, age 5" << endl;
    cout << "Missy, age 11" << endl;
    cout << "Penelope, age 11" << endl;
    cout << "Jack, age 11" << endl << endl;

    // Inserting 10 pets for testing
    tree.insertPet("Rocco", 3);
    tree.insertPet("Jade", 9);
    tree.insertPet("Gus", 13);
    tree.insertPet("Sterling", 1);
    tree.insertPet("Bubba", 7);
    tree.insertPet("Link", 8);
    tree.insertPet("Gandy", 5);
    tree.insertPet("Missy", 11);
    tree.insertPet("Penelope", 6);
    tree.insertPet("Jack", 4);

    // Attemptint to insert a duplicate Pet name
    cout << "Now testing inserting a duplicate value: (Duplicate checking message below)" << endl;
    tree.insertPet("Link", 8);
    cout << endl;

    // Searching for pet in tree
    tree.searchPet("Link");
    cout << endl;

    // Deleting a node from the tree
    tree.deleteNode(tree.getRoot(), "Sterling");
    cout << "Sterling was deleted from the tree" << endl << endl;

    // InOrder traversal of tree
    cout << "InOrder display: " << endl;
    tree.inorderDisplay();
    cout << endl;

    // PreOrder traversal of tree
    cout << "PreOrder display: " << endl;
    tree.preorderDisplay();
    cout << endl;

    // PostOrder traversal of tree
    cout << "PostOrder display: " << endl;
    tree.postorderDisplay();
    cout << endl;

    // Finding parent node of a given node
    tree.displayParent("Link");
    cout << endl;

    // Finding predecessor of given node
    tree.displayPredecessor("Penelope");
    cout << endl;

    // Number of nodes in tree
    cout << "Number of nodes in the tree is: " << tree.totalNodes(tree.getRoot()) << endl << endl;

    // Number of internal nodes in tree
    cout << "Number of internal nodes in the tree is: " << tree.internalNodes(tree.getRoot()) << endl << endl;
    
    // Number of nodes at a given level in tree
    cout << "Number of nodes level 1 in the tree is: " << tree.levelNodes(tree.getRoot(), 1) << endl << endl;

    // Height of the tree
    cout << "The height of the tree is: " << tree.height(tree.getRoot()) << endl << endl;

    // Check if tree is balanced or not
    if (tree.isBalanced(tree.getRoot())) {
        cout << "True, tree is balanced" << endl << endl;
    } else {
        cout << "False, tree is unbalanced" << endl << endl;
    }

    // Destroying the tree
    cout << "The tree is destroyed: " << tree.destroyTree(tree.getRoot()) << endl << endl;
}