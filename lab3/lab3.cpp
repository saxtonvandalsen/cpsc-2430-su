// Saxton Van Dalsen
// lab3.cpp
// 1/21/2024

// Purpose: This program implements a Binary Search Tree class structure to manage
// a pet shelter. It allows a user to insert pets into the shelter with a name and
// age, search for the pets based on their ages, and display each of the pets in 
// the shelter through recursive traversal methods including inorder, preorder, and
// postorder.

#include <iostream>

using namespace std;

// BST Class designed for a pet shelter
class ShelterBST {
    
    private:
        struct Pet {
        string name;
        int age;

            // Pet constructor initializing member variables
            Pet(const string& petName, int petAge) {
                name = petName;
                age = petAge;
            }
        };
 
        struct TreeNode {
            Pet* pet; // Pointer to a Pet object representing the data of the node
            TreeNode* left; // Pointer to the left subtree
            TreeNode* right; // Pointer to the right subtree
        };

        TreeNode* root; // Root used for struct TreeNode

        // Recursive BST insertion function that will add and compare a 
        // new Pet by it's age in an ordered fashion
        TreeNode* insert(TreeNode* root, Pet* pet) {
        
            // Base case, if tree is empty
            if (root == nullptr) {

                // Creating new TreeNode as root
                root = new TreeNode();
                root->left = nullptr; // Initilizing left to nullptr
                root->right = nullptr; // Initilizing right to nullptr

                // Creating new Pet and assigning it to the new root TreeNode
                root->pet = new Pet(pet->name, pet->age);
            } else {

                // Comparing age of current TreeNode with the given age of the Pet
                if (pet->age == root->pet->age) {

                    // Displaying message to user that Pet with that age already
                    // exitsts. Not allowing duplicate pet age values
                    cout << "A pet with age " << pet->age << " already exists." << endl;
                } 
                
                // Comparing Pet's age with right subtree
                else if (pet->age > root->pet->age) {
                    
                    // If right subtree is empty
                    if (root->right == nullptr) {
                        root->right = new TreeNode();
                        root->right->left = nullptr;
                        root->right->right = nullptr;

                        // Creating a new Pet and adding it as a new right Leafnode
                        root->right->pet = new Pet(pet->name, pet->age);
                    } else {

                        // Recursively adding the new Pet to the right subtree
                        root->right = insert(root->right, pet);
                    }
                } 
                
                // Comparing Pet's age with left subtree
                else {

                    // If left subtree is empty
                    if (root->left == nullptr) {
                        root->left = new TreeNode();
                        root->left->left = nullptr;
                        root->left->right = nullptr;
                        
                        // Creating a new Pet and adding it as a new left Leafnode
                        root->left->pet = new Pet(pet->name, pet->age);
                    } else {

                        // Recursively adding the new Pet to the left subtree
                        root->left = insert(root->left, pet);
                    }
                }
            }
            return root;
        }

        // Recursive BST search function that returns pointer to
        // TreeNode that matches the given age
        // Nullptr if no match is found 
        TreeNode* search(TreeNode* root, int age) {
            
            // Base case, if tree is empty
            if (root == nullptr) {
                return nullptr; // Shelter is empty
            } 
            
            // If age equals Pet's age return 
            else if (age == root->pet->age) {
                return root;
            } 
            
            // If age is greater than target, then recursively search
            // and return the result of the right subtree
            else if (age > root->pet->age) {
                return search(root->right, age);
            } 

            // If age is less than target, then recursively search
            // and return the result of the left subtree
            else {
                return search(root->left, age);
            }
        }
        
        // Recursive function to execute inorder traversal of ShelterBST
        void inorder(TreeNode* root) {
            
            // Base case checks if current node is not null
            if (root != nullptr) {

                // Recursively traverse left subtree
                inorder(root->left);

                // Print pet's data
                cout << "Pet's name: " << root->pet->name << ", Age: " << root->pet->age << endl;

                // Recursively traverse right subtree
                inorder(root->right);
            }
        }

        // Recursive function to execute preorder traversal of ShelterBST
        void preorder(TreeNode* root) {
            
            // Base case checks if current node is not null
            if (root != nullptr) {

                // Print pet's data
                cout << "Pet's name: " << root->pet->name << ", Age: " << root->pet->age << endl;

                // Recursively traverse left subtree
                inorder(root->left);

                // Recursively traverse right subtree
                inorder(root->right);
            }
        }

        // Recursive function to execute postorder traversal of ShelterBST
        void postorder(TreeNode* root) {
            
            // Base case checks if current node is not null
            if (root != nullptr) {

                // Recursively traverse left subtree
                inorder(root->left);

                // Recursively traverse right subtree
                inorder(root->right);

                // Print pet's data
                cout << "Pet's name: " << root->pet->name << ", Age: " << root->pet->age << endl;
            }
        }

    public:

        // Constructor for ShelterBST
        ShelterBST() {
            root = nullptr;
        }

        // Insert a new pet with provided name and age into the shelter
        void insertPet(string name, int age) {
            root = insert(root, new Pet(name, age));
        }

        // Search for a pet by provided age in the shelter
        void searchPet(int age) {
            TreeNode* result = search(root, age);
            
            // Displaying name of pet found
            if (result) {
                cout << "Pet's name with age " << age << " is: " << result->pet->name << endl;
            } 
            
            // If not found, letting the user know
            else {
                cout << "There is no pet with that age in the shelter." << endl;
            }
        }

        // Displaying all pets through inorder traversal of the shelter
        void inorderDisplay() {
            inorder(root);
        }

        // Displaying all pets through preorder traversal of the shelter
        void preorderDisplay() {
            preorder(root);
        }

        // Displaying all pets through postorder traversal of the shelter
        void postorderDisplay() {
            postorder(root);
        }
};

// Main fuction to test class implementation
// Inserting 10 pets with all different ages
// Displaying the three different traversals  of the BST
// Conducting one successful search and one unsuccessful search
int main () {

    ShelterBST tree; // ShelterBST instance

    // Inserting 10 pets into the Shelter BST
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

    // Inorder display
    cout << "Displaying inorder traversal: " << endl << endl;
    tree.inorderDisplay();
    cout << endl << endl;

    // Preorder display
    cout << "Displaying preorder traversal: " << endl << endl;
    tree.preorderDisplay();
    cout << endl << endl;

    // Postorder display
    cout << "Displaying postorder traversal: " << endl << endl;
    tree.postorderDisplay();
    cout << endl << endl;

    // Successful search
    tree.searchPet(9);

    // Unsuccessful search
    tree.searchPet(99);

    return 0;
}