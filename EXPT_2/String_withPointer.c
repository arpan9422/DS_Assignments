#include <stdio.h>
#include <string.h>

// Function to find substring
int substring(char *str, char *substr) {
    char *p1, *p2, *p3;
    for (p1 = str; *p1 != '\0'; p1++) {
        p2 = p1;
        p3 = substr;
        while (*p2 == *p3 && *p3 != '\0') {
            p2++;
            p3++;
        }
        if (*p3 == '\0') {
            return p1 - str; // Return index of substring
        }
    }
    return -1; // Substring not found
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (start < end) {
        if (*start != *end) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

// Function to compare two strings
int compareStrings(char *str1, char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

// Function to copy one string to another
void copyString(char *source, char *destination) {
    while (*source) {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0'; // Null-terminate the destination string
}

// Function to reverse a string
void reverseString(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char str[100], substr[100];
    int choice;
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Choose an operation:\n");
    printf("1. Substring\n");
    printf("2. Palindrome\n");
    printf("3. Compare\n");
    printf("4. Copy\n");
    printf("5. Reverse\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    char copy[100];
    char str2[100];
    int index, result;

    switch (choice) {
        case 1:
            printf("Enter substring to search: ");
            scanf("%s", substr);
            index = substring(str, substr);
            if (index != -1) {
                printf("Substring found at index: %d\n", index);
            } else {
                printf("Substring not found\n");
            }
            break;

        case 2:
            if (isPalindrome(str)) {
                printf("The string is a palindrome.\n");
            } else {
                printf("The string is not a palindrome.\n");
            }
            break;

        case 3:
            printf("Enter another string: ");
            scanf("%s", str2);
            result = compareStrings(str, str2);
            if (result < 0) {
                printf("The first string is smaller.\n");
            } else if (result > 0) {
                printf("The second string is smaller.\n");
            } else {
                printf("Both strings are equal.\n");
            }
            break;

        case 4:
            copyString(str, copy);
            printf("Copied string: %s\n", copy);
            break;

        case 5:
            reverseString(str);
            printf("Reversed string: %s\n", str);
            break;

        default:
            printf("Invalid choice. Please choose a valid operation.\n");
    }
    return 0;
}
