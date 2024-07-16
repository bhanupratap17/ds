#include <stdio.h>
#define N 5  // Define the maximum size of the stack

int stack[N];
int top = -1;  // Initialize the top of the stack

// Function to push an element onto the stack
void push() {
    if (top == N - 1) {
        printf("Overflow\n");
    } else {
        int x;
        printf("Enter value: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("%d pushed onto stack\n", x);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack is underflow\n");
    } else {
        int item = stack[top];
        top--;
        printf("%d popped from stack\n", item);
    }
}

// Function to peek at the top element of the stack
void peek() {
    if (top == -1) {
        printf("Stack is underflow\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function to provide a menu-driven interface
int main() {
    int choice;
    do {
        printf("Enter choice:\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 0);
    return 0;
}
