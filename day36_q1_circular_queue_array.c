// Day 36 - Question 1: Circular Queue Using Array
// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;
int size = 0;

// Enqueue operation
void enqueue(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    size++;
}

// Dequeue operation
void dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return;
    }

    front = (front + 1) % MAX;
    size--;
}

// Display queue from front to rear
void display() {
    if (size == 0) {
        printf("Queue is Empty");
        return;
    }

    int i = front;
    for (int count = 0; count < size; count++) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, value;

    // Input number of elements
    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // Number of dequeue operations
    scanf("%d", &m);

    // Perform dequeue operations
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Reinsert removed elements to demonstrate circular queue
    for (int i = 0; i < m; i++) {
        enqueue((i + 1) * 10);
    }

    // Display queue
    display();

    return 0;
}