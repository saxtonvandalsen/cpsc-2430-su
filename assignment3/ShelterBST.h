// Saxton Van Dalsen
// ShelterBST.h
// 01/30/2023

// Purpose: Header file for class ShelterBST to hold all declarations

#ifndef SHELTERBST_H
#define SHELTERBST_H

#include <string>
using namespace std;

// Binary search tree class for a pet shelter system
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

        TreeNode* insert(TreeNode* root, Pet* pet);
        TreeNode* search(TreeNode* root, string name);
        TreeNode* parent(TreeNode* root, string name);
        TreeNode* predecessor(TreeNode* root, string name);
        void inorder(TreeNode* root);
        void preorder(TreeNode* root);
        void postorder(TreeNode* root);

    public:

        ShelterBST();
        void insertPet(string name, int age);
        void searchPet(string age);
        void displayParent(string name);
        void displayPredecessor(string name);
        int totalNodes(TreeNode* root);
        int internalNodes(TreeNode* root);
        int levelNodes(TreeNode* root, int level);
        int height(TreeNode* root);
        bool isBalanced(TreeNode* root);
        TreeNode* deleteNode(TreeNode* root, string name);
        TreeNode* destroyTree(TreeNode* root);
        TreeNode* getRoot() const;
        void inorderDisplay();
        void preorderDisplay();
        void postorderDisplay();
};

#endif