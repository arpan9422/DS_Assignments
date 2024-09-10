#include <stdio.h>
#include <string.h>

// Define the structure for a component with various attributes
struct component {
    int srNo;            // Serial number
    char name[10];       // Name of the component
    char symbol[3];      // Symbol of the component
    int value;           // Value of the component
    float cost;          // Cost of the component (in float for precision)
};

// Function prototypes
void create(struct component s[], int size);
void display(struct component s[], int size);
void searchName(struct component s[], int size);
void searchSymbol(struct component s[], int size);
void sortCost(struct component s[], int size);
void sortValue(struct component s[], int size);
void update(struct component s[], int size);
void delete(struct component s[], int *size);

int main() {
    int size, choice, choice2, choice3;
    
    // Ask the user to input the number of items to be added
    printf("Enter number of items to be added: ");
    scanf("%d", &size);

    // Declare an array of struct 'component' with the given size
    struct component s[size];
    
    // Create the list of components
    create(s, size);
    
    // Display the list of components
    display(s, size);
    
    // Ask the user to choose an operation to perform
    printf("Enter the operation to perform on the list :-\n1. Search\n2. Sort\n3. Update\n4. Delete\n");
    scanf("%d", &choice);
   
    // Perform the selected operation
    switch(choice){
        case 1 :
            printf("\nSearch by :-\n1. Name\n2. Symbol\n");
            scanf("%d", &choice2);
            switch(choice2){
                case 1:
                    searchName(s, size);
                    break;
                case 2:
                    searchSymbol(s, size);
                    break;
            }
            break;

        case 2 :
            printf("\nSort by :-\n1. Cost\n2. Value\n");
            scanf("%d", &choice3);
            switch(choice3){
                case 1:
                    sortCost(s, size);
                    break;
                case 2:
                    sortValue(s, size);
                    break;
            }
            break;

        case 3 :
            update(s, size);
            break;

        case 4 :
            delete(s, &size);
            display(s, size);  // Display the list after deletion
            break;
    }
    return 0;
}

// Function to create the list of components
void create(struct component s[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Name of Component: ");
        scanf("%s", s[i].name);
        printf("Symbol: ");
        scanf("%s", s[i].symbol);
        printf("Value: ");
        scanf("%d", &s[i].value);
        printf("Cost: ");
        scanf("%f", &s[i].cost);

        s[i].srNo = i + 1;  // Assign serial number automatically
    }
}

// Function to display the list of components
void display(struct component s[], int size) {
    printf("SrNo.\tName\t\tSymbol\tValue\tCost\n");
    printf("---------------------------------------------------------\n");

    for(int i = 0; i < size; i++) {
        // Display each component with two decimal places for the cost
        printf("%d\t%s\t%s\t%d\t%.2f\n", s[i].srNo, s[i].name, s[i].symbol, s[i].value, s[i].cost);
    }
}

// Function to search for a component by its name
void searchName(struct component s[], int size) {
    char nameFind[20];
    int found = 0;

    printf("Enter the name: ");
    scanf("%s", nameFind);
    printf("Entries with the same name will be displayed below :-\n");
    printf("SrNo.\tName\t\tSymbol\tValue\tCost\n");
    printf("---------------------------------------------------------\n");

    for(int j = 0; j < size; j++) {
        if(strcmp(s[j].name, nameFind) == 0) {
            printf("%d\t%s\t\t%s\t%d\t%.2f\n", s[j].srNo, s[j].name, s[j].symbol, s[j].value, s[j].cost);
            found = 1;
        }
    }

    if (!found) {
        printf("No component with the name '%s' found.\n", nameFind);
    }
}

// Function to search for a component by its symbol
void searchSymbol(struct component s[], int size) {
    char symbolFind[3];
    int found = 0;

    printf("Enter the symbol: ");
    scanf("%s", symbolFind);
    printf("Entries with the same symbol will be displayed below :-\n");
    printf("SrNo.\tName\t\tSymbol\tValue\tCost\n");
    printf("---------------------------------------------------------\n");

    for(int j = 0; j < size; j++) {
        if(strcmp(s[j].symbol, symbolFind) == 0) {
            printf("%d\t%s\t\t%s\t%d\t%.2f\n", s[j].srNo, s[j].name, s[j].symbol, s[j].value, s[j].cost);
            found = 1;
        }
    }

    if (!found) {
        printf("No component with the symbol '%s' found.\n", symbolFind);
    }
}

// Function to sort the list of components by cost
void sortCost(struct component s[], int size) {
    struct component temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(s[i].cost > s[j].cost) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("List sorted by cost.\n");
    display(s, size);
}

// Function to sort the list of components by value
void sortValue(struct component s[], int size) {
    struct component temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(s[i].value > s[j].value) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("List sorted by value.\n");
    display(s, size);
}

// Function to update a component's details
void update(struct component s[], int size) {
    int srNo;
    printf("Enter the SrNo of the component to update: ");
    scanf("%d", &srNo);

    for(int i = 0; i < size; i++) {
        if(s[i].srNo == srNo) {
            printf("Updating component with SrNo %d\n", srNo);
            printf("Enter new name: ");
            scanf("%s", s[i].name);
            printf("Enter new symbol: ");
            scanf("%s", s[i].symbol);
            printf("Enter new value: ");
            scanf("%d", &s[i].value);
            printf("Enter new cost: ");
            scanf("%f", &s[i].cost);
            printf("Component updated successfully.\n");
            return;
        }
    }

    printf("Component with SrNo %d not found.\n", srNo);
}

// Function to delete a component from the list
void delete(struct component s[], int *size) {
    int srNo;
    printf("Enter the SrNo of the component to delete: ");
    scanf("%d", &srNo);

    int found = 0;
    for(int i = 0; i < *size; i++) {
        if(s[i].srNo == srNo) {
            found = 1;
            for(int j = i; j < *size - 1; j++) {
                s[j] = s[j + 1];
            }
            (*size)--;
            printf("Component with SrNo %d deleted successfully.\n", srNo);
            return;
        }
    }

    if(!found) {
        printf("Component with SrNo %d not found.\n", srNo);
    }
}
