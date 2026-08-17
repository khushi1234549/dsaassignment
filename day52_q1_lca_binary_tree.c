// Day 52 - Question 1: LCA in Binary Tree
// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7
// 4 5

// Output:
// 2

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

// Find LCA
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;

    return right;
}

int main() {
    int n, p, q;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, n);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}