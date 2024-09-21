#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

// Structure for stack
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", item);
        return;
    }
    s->items[++(s->top)] = item;
    printf("%d pushed to stack\n", item);
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    int poppedItem = s->items[(s->top)--];
    printf("%d popped from stack\n", poppedItem);
    return poppedItem;
}

// Function to insert an element onto the stack
void insert(Stack* s, int item) {
    push(s, item);
}

// Function to delete an element from the stack
int delete(Stack* s) {
    return pop(s);
}

// Function to display the stack
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    Stack s;
    initStack(&s);
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&s, value);
                break;
            case 4:
                delete(&s);
                break;
            case 5:
                display(&s);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
