#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========================= Lab Work #8 ========================= //
// Function for processing a one-dimensional array
void processOneDimensionalArray(int arr[], int size) {
    printf("One-Dimensional Array Elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Example: Calculate the sum of the array elements
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("Sum of elements: %d\n", sum);

    // Example: Find the maximum element
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Maximum element: %d\n", max);
}

// ========================= Lab Work #9 ========================= //
// Function for processing a two-dimensional array
void processTwoDimensionalArray(int rows, int cols) {
    int matrix[rows][cols];

    // Input elements for the matrix
    printf("Enter elements for %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Example: Calculate the sum of each row
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Sum of row %d: %d\n", i, rowSum);
    }
}

// ========================= Lab Work #10 ========================= //
// Function for dynamically allocating a one-dimensional array
void dynamicallyAllocateOneDimensionalArray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d elements for the dynamically allocated array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    processOneDimensionalArray(arr, size);

    free(arr); // Free allocated memory
}

// Function for dynamically allocating a two-dimensional array
void dynamicallyAllocateTwoDimensionalArray(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));

    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for row %d!\n", i);
            return;
        }
    }

    printf("Enter elements for dynamically allocated %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the dynamically allocated matrix
    printf("Dynamically Allocated Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// ========================= Lab Work #11 ========================= //
// Structure definition
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Function to process student data using structures
void processStructs() {
    Student student;

    printf("Enter student name: ");
    scanf("%s", student.name);
    printf("Enter student age: ");
    scanf("%d", &student.age);
    printf("Enter student GPA: ");
    scanf("%f", &student.gpa);

    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %.2f\n", student.gpa);
}

// ========================= Main Function ========================= //
int main() {
    // Lab Work #8: One-Dimensional Arrays
    printf("\n--- Lab Work #8: One-Dimensional Arrays ---\n");
    int arr8[] = {1, 2, 3, 4, 5};
    processOneDimensionalArray(arr8, 5);

    // Lab Work #9: Two-Dimensional Arrays
    printf("\n--- Lab Work #9: Two-Dimensional Arrays ---\n");
    processTwoDimensionalArray(2, 3);

    // Lab Work #10: Dynamically Allocated Arrays
    printf("\n--- Lab Work #10: Dynamically Allocated Arrays ---\n");
    dynamicallyAllocateOneDimensionalArray(5);
    dynamicallyAllocateTwoDimensionalArray(2, 3);

    // Lab Work #11: Structs in C
    printf("\n--- Lab Work #11: Structs in C ---\n");
    processStructs();

    return 0;
}
