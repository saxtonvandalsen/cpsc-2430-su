// Saxton Van Dalsen
// ShelterBST.cpp
// 01/30/2023

// Purpose: Implementation file of ShelterBST that includes 15 functions to be used
// for in the user interface in assignment3.cpp (main file) 

#include "ShelterBST.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Default constructor
ShelterBST::ShelterBST() {
    root = nullptr;
}

// Recursive BST insertion function that will add and compare a 
// new Pet by it's age in an ordered fashion
ShelterBST::TreeNode* ShelterBST::insert(TreeNode* root, Pet* pet) {

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
        if (pet->name == root->pet->name) {

            // Displaying message to user that Pet with that age already
            // exitsts. Not allowing duplicate pet age values
            cout << "A pet with name " << pet->name << " already exists." << endl;
        } 
        
        // Comparing Pet's age with right subtree
        else if (pet->name > root->pet->name) {
            
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
ShelterBST::TreeNode* ShelterBST::search(TreeNode* root, string name) {

    // Base case, if tree is empty
    if (root == nullptr) {
        return nullptr; // Shelter is empty
    } 

    // If age equals Pet's age return 
    else if (name == root->pet->name) {
        return root;
    } 

    // If age is greater than target, then recursively search
    // and return the result of the right subtree
    else if (name > root->pet->name) {
        return search(root->right, name);
    } 

    // If age is less than target, then recursively search
    // and return the result of the left subtree
    else {
        return search(root->left, name);
    }
}

// Recursive function to find the parent node for a given pet's name
ShelterBST::TreeNode* ShelterBST::parent(TreeNode* root, string name) {

    // If tree is empty, return null
    if (root == nullptr) {
        return nullptr;
    }

    // If either the left or the right child's name matches the given
    // name then return that parent node
    if ((root->left != nullptr && root->left->pet->name == name) || (root->right != nullptr && root->right->pet->name == name)) {
            return root;
        }

    // Recursively searching either subtree for a parent that has a
    // child with the given name
    if (name < root->pet->name) {
        return parent(root->left, name);
    } else {
        return parent(root->right, name);
    }
}

// Recursive function to return the predecessor for a given node with 2 children
ShelterBST::TreeNode* ShelterBST::predecessor(TreeNode* root, string name) {
    
    // Base case
    if (root == nullptr) {
        return nullptr;
    }

    if (name == root->pet->name && root->left != nullptr && root->right != nullptr) {
        return root;
    }

    if (name < root->pet->name) {
        return predecessor(root->left, name);
    } else {
        return predecessor(root->right, name);
    }
}

// Recursive function to execute inorder traversal of ShelterBST
void ShelterBST::inorder(TreeNode* root) {
    
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
void ShelterBST::preorder(TreeNode* root) {
    
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
void ShelterBST::postorder(TreeNode* root) {
    
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

// Insert a new pet with provided name and age into the shelter
void ShelterBST::insertPet(string name, int age) {
    root = insert(root, new Pet(name, age));
}

// Search for a pet by provided age in the shelter
void ShelterBST::searchPet(string name) {
    TreeNode* result = search(root, name);
    
    // Displaying name of pet found
    if (result) {
        cout << "Pet's name with age " << result->pet->age << " is: " << result->pet->name << endl;
    } 
    
    // If not found, letting the user know
    else {
        cout << "There is no pet with that name in the shelter." << endl;
    }
}

// Display the Parent node for a given pet name
void ShelterBST::displayParent(string name) {
    TreeNode* foundParent = parent(root, name);

    // Displaying name and age of parent pet
    if (foundParent) {
        cout << "The parent pet's name " << foundParent->pet->name << " is " << foundParent->pet->age << " years old." << endl;
    }

    // If not found, letting the user know
    else {
        cout << "There is no pet with that name in the shelter." << endl;
    }
}

// Display the predecessor for a given node with 2 children
void ShelterBST::displayPredecessor(string name) {
    TreeNode* foundPredecessor = parent(root, name);

    // Displaying name and age of predecessor pet
    if (foundPredecessor) {
        cout << "The parent pet's name " << foundPredecessor->pet->name << " is " << 
        foundPredecessor->pet->age << " years old." << endl;
    }

    // If not found, letting the user know
    else {
        cout << "There is no pet with that name in the shelter." << endl;
    }
}

// Recursively return total number of nodes in the tree 
int ShelterBST::totalNodes(TreeNode* root) {

    // If tree is empty, return 0
    if (root == nullptr) {
        return 0;
    }

    // Recursively traverse left nodes and right nodes
    int leftNodes = totalNodes(root->left);
    int rightNodes = totalNodes(root->right);

    // Return sum of all nodes plus root
    return 1 + leftNodes + rightNodes;
}

// Recursively return the number of internal nodes in the tree
int ShelterBST::internalNodes(TreeNode* root) {

    // If tree is empty
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return 0;
    }

    // Recursively traverse left nodes and right nodes 
    int leftNodes = internalNodes(root->left);
    int rightNodes = internalNodes(root->right);

    // Return sum of internal nodes plus root
    return 1 + leftNodes + rightNodes;
}

// Recursively return the number of nodes at a given level
int ShelterBST::levelNodes(TreeNode* root, int level) {

    // If tree is empty, return 0
    if (root == nullptr || level < 0) {
        return 0;
    }

    // If level is 0, return 1 for root
    if (level == 0) {
        return 1;
    }

    // Recursively traverse nodes at the given level for
    // left subtree and right subtree, and accumulate the counts
    int leftNodes = levelNodes(root->left, level - 1);
    int rightNodes = levelNodes(root->right, level - 1);

    // Return the total sum calculated for the current level
    return leftNodes + rightNodes;
}

// Recursively return the height of the tree
int ShelterBST::height(TreeNode* root) {

    // If empty, return 0
    if (root == nullptr) {
        return 0;
    } else {

        // Traversing to get the height of root's
        // subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Checking which subtree has the overall
        // correct height, returning the height
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

// Boolean function to check if BST is balanced or not,
// may differ by at most 1
bool ShelterBST::isBalanced(TreeNode* root) {

    // If tree is empty, return false
    if (root == nullptr) {
        return false;
    }

    // Checking the height of each subtree
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // If the difference in height of the subtrees is greater than
    // 1, then it is not balanced. Return false
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    // Recursively checking the balance of the left and right subtrees
    return isBalanced(root->left) && isBalanced(root->right);
}

// Recursively deleting a node based on a Pet's name,
// reconstructing BST
ShelterBST::TreeNode* ShelterBST::deleteNode(TreeNode* root, string name) {
    
    // Base case: Tree is empty
    if (root == nullptr) {
        return nullptr;
    }

    // Find the parent of the node to be deleted
    TreeNode* parentNode = parent(root, name);

    // Search the node to be deleted
    TreeNode* nodeToDelete = search(root, name);

    // If the node to delete has one or no children
    if (nodeToDelete->left == nullptr) {
        TreeNode* temp = nodeToDelete->right; // To preserve right subtree
        delete nodeToDelete; // Delete node
        if (parentNode == nullptr) {
            return temp; // If node to be deleted is the root
        } else if (parentNode->left == nodeToDelete) {
            parentNode->left = temp; // If node to be deleted was left child
        } else {
            parentNode->right = temp; // If node to be deleted was right child
        }
    } else if (nodeToDelete->right == nullptr) {
        TreeNode* temp = nodeToDelete->left; // To preserve left subtree
        delete nodeToDelete; // Delete node
        if (parentNode == nullptr) {
            return temp; // If node to be deleted is the root
        } else if (parentNode->left == nodeToDelete) {
            parentNode->left = temp; // If node to be deleted was left child
        } else {
            parentNode->right = temp; // If node to be deleted was right child
        }
    } else {
        // Node to delete has two children so now
        // find the in-order predecessor
        TreeNode* predecessorNode = predecessor(root, name);

        // Replace the data of the node to delete with the data of the predecessor
        nodeToDelete->pet = predecessorNode->left->pet;

        // Recursively delete the predecessor, handling the case where the predecessor has no
        // or one child. Ensuring the tree remains after this replacement
        predecessorNode->left = deleteNode(predecessorNode->left, predecessorNode->left->pet->name);
    }
    return root;
}

// Function to destroy the tree and deallocates dynamic memory
ShelterBST::TreeNode* ShelterBST::destroyTree(TreeNode* root) {
    
    // Delete each node from the left and right subtrees then delete root
    if (root != nullptr) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
    return nullptr;
}

// Displaying all pets through inorder traversal of the shelter
void ShelterBST::inorderDisplay() {
    inorder(root);
}

// Displaying all pets through preorder traversal of the shelter
void ShelterBST::preorderDisplay() {
    preorder(root);
}

// Displaying all pets through postorder traversal of the shelter
void ShelterBST::postorderDisplay() {
    postorder(root);
}   

// Added for required functionaily as a paramater to required
// functions above
ShelterBST::TreeNode* ShelterBST::getRoot() const {
    return root;
}
