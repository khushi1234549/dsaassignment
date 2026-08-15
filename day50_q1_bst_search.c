// Day 50 - Question 1: BST Search
// Problem: BST Search

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Search in BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

int main() {
    int n, value;

    scanf("%d", &n);

    struct Node* root = NULL;

    // Create BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Value to search
    scanf("%d", &value);

    struct Node* result = search(root, value);

    if (result != NULL)
        printf("%d", result->data);
    else
        printf("-1");

    return 0;
}