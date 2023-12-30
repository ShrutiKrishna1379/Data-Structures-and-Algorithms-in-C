#include <stdio.h>

int main() {
    int numRows, numCols, elementSize, baseAddress;

    // Input array properties
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);

    printf("Enter the number of columns: ");
    scanf("%d", &numCols);

    printf("Enter the size of each element (in bytes): ");
    scanf("%d", &elementSize);

    printf("Enter the base address: ");
    scanf("%d", &baseAddress);

    // Specify the target element
    int targetRow, targetCol;

    printf("Enter the row of the target element: ");
    scanf("%d", &targetRow);

    printf("Enter the column of the target element: ");
    scanf("%d", &targetCol);

    // Calculate the address using the row-major order formula
    int address = baseAddress + ((targetRow - 1) * numCols + (targetCol - 1)) * elementSize;

    // Print the result
    printf("The address of arr[%d][%d] is: %d\n", targetRow, targetCol, address);

    return 0;
}
