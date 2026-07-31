// Day 35 - Question 1: Queue Using Array
// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = value;
}

// Dequeue operation
void dequeue() {
    if (front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    front++;
}

// Display queue from front to rear
void display() {
    if (front > rear) {
        printf("Queue is Empty");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, value;

    // Input number of elements
    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // Display queue
    display();

    return 0;
}