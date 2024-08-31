#include <stdio.h>

void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
int linearSearch(int arr[], int n, int x);
int binarySearch(int arr[], int left, int right, int x);
void modify(int arr[], int n);
void insert(int arr[], int *n);
void delete(int arr[], int *n);


int main() {
    int choice;
    int sortChoice, searchChoice;
    int arr[100];
    int n, i, x, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nArray elements are: ");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        
        printf("\nMenu:");
        printf("\n 1. Sorting");
        printf("\n 2. Searching");
        printf("\n 3. Insert");
        printf("\n 4. Modify");
        printf("\n 5. Delete");
        printf("\n 6. Exit");
        printf("\nEnter choice to perform: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nSort Options:");
                printf("\n 1. Insertion Sort");
                printf("\n 2. Selection Sort");
                printf("\n 3. Bubble Sort");
                printf("\n 4. Merge Sort");
                printf("\nEnter sorting choice: ");
                scanf("%d", &sortChoice);

                switch (sortChoice) {
                    case 1:
                        insertionSort(arr, n);
                        break;
                    case 2:
                        selectionSort(arr, n);
                        break;
                    case 3:
                        bubbleSort(arr, n);
                        break;
                    case 4:
                        mergeSort(arr, 0, n - 1);
                        break;
                    default:
                        printf("Invalid sort choice.\n");
                }
                break;

            case 2:
                printf("\nSearch Options:");
                printf("\n 1. Linear Search");
                printf("\n 2. Binary Search");
                printf("\nEnter searching choice: ");
                scanf("%d", &searchChoice);

                switch (searchChoice) {
                    case 1:
                    printf("\n Enter the number to  be find :");
                    scanf("%d", &x);
                        result = linearSearch(arr, n, x);
                                if (result != -1)
                                    printf("Element found at index %d\n", result);
                                else
                                    printf("Element not found\n");
                        break;
                    case 2:
                    printf("\n Enter the number to  be find :");
                    scanf("%d", &x);
                        insertionSort(arr, n); 
                        result = binarySearch(arr, 0, n - 1, x);
                        if (result != -1)
                            printf("Element found at index %d\n", result);
                        else
                            printf("Element not found\n");
                        break;
                    default:
                        printf("Invalid search choice.\n");
                }
                break;

            case 3:
                insert(arr, &n);
                break;
            case 4:
                modify(arr, n);
                break;
            case 5:
                delete(arr, &n);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) { 
        int key = arr[i]; 
        int j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 

        // Display array after each pass
        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++) 
            printf("%d ", arr[k]); 
        printf("\n");
    } 
    printf("\nFinal sorted array: "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n");
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        // Display array after each pass
        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++) 
            printf("%d ", arr[k]); 
        printf("\n");
    }
    printf("\nFinal sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int swapped = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {                
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }

        // Display array after each pass
        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++) 
            printf("%d ", arr[k]); 
        printf("\n");

        if (!swapped) {
            break;
        }
    }
    printf("\nFinal sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



//merge is the function which is called in mergesort function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
        
        printf("Merging: ");
        for (int i = left; i <= right; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}


int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}



int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}


void modify(int arr[], int n) {
    int index, newValue;
    
    printf("Enter the index of the element to modify (0 to %d): ", n-1);
    scanf("%d", &index);
    
    if (index < 0 || index >= n) {
        printf("Invalid index!\n");
        return;
    }
    
    printf("Enter the new value: ");
    scanf("%d", &newValue);
    
    arr[index] = newValue;
    printf("Element at index %d has been updated to %d.\n", index, newValue);
}


void insert(int arr[], int *n) {
    int index, value;

    if (*n >= 100) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    printf("Enter the index where you want to insert the new element (0 to %d): ", *n);
    scanf("%d", &index);

    if (index < 0 || index > *n) {
        printf("Invalid index!\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    (*n)++;
    printf("Element inserted at index %d.\n", index);
}


void delete(int arr[], int *n) {
    int index;

    if (*n <= 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter the index of the element to delete (0 to %d): ", *n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *n) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
    printf("Element deleted from index %d.\n", index);
}
