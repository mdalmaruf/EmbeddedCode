// To create a Binary Search Tree (BST) in C with the values 5, 2, 8, and 20, you can follow these steps:


#include <stdio.h>
#include <stdlib.h>

// Define the structure for the tree node
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        // The tree is empty, so return a new node
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to print the BST in inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

// Main function to demonstrate the creation of BST
int main() {
    struct Node* root = NULL;

    // Inserting nodes into the BST
    root = insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 8);
    insertNode(root, 20);

    // Print the BST in inorder traversal
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
