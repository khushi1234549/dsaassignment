// Day 42 - Question 1: Reverse a Queue Using Stack
// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10

#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int value) {
    queue[++rear] = value;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push
void push(int value) {
    stack[++top] = value;
}

// Pop
int pop() {
    return stack[top--];
}

int main() {
    int n, value;

    // Input number of elements
    scanf("%d", &n);

    // Read queue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // Move queue to stack
    while (front <= rear) {
        push(dequeue());
    }

    // Move stack back to queue
    front = 0;
    rear = -1;

    while (top != -1) {
        enqueue(pop());
    }

    // Display reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}