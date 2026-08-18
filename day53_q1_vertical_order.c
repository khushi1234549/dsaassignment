// Day 53 - Question 1: Print Binary Tree Vertical Order
// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

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

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[1000];
    int front = 0, rear = 0;
    int i = 1;

    queue[rear++] = root;

    while (i < n) {
        struct Node* current = queue[front++];

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

// Store nodes according to horizontal distance
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[1000];
    int hd[1000];

    int front = 0, rear = 0;

    int minHD = 0, maxHD = 0;

    queue[rear] = root;
    hd[rear++] = 0;

    // Store node values and horizontal distances
    int values[1000];
    int distances[1000];
    int count = 0;

    while (front < rear) {
        struct Node* current = queue[front];
        int currentHD = hd[front];
        front++;

        values[count] = current->data;
        distances[count] = currentHD;
        count++;

        if (currentHD < minHD)
            minHD = currentHD;

        if (currentHD > maxHD)
            maxHD = currentHD;

        if (current->left != NULL) {
            queue[rear] = current->left;
            hd[rear++] = currentHD - 1;
        }

        if (current->right != NULL) {
            queue[rear] = current->right;
            hd[rear++] = currentHD + 1;
        }
    }

    // Print from leftmost column to rightmost column
    for (int column = minHD; column <= maxHD; column++) {
        for (int i = 0; i < count; i++) {
            if (distances[i] == column) {
                printf("%d ", values[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
