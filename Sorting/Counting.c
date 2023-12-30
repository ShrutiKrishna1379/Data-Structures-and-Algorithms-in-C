#include <stdio.h>

void countingSort(int arr[], int n);

int main() {
    int n, i;

    printf("Enter number of elements:");
    scanf("%d", &n);

    printf("Enter %d integers:", n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted list in ascending order:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1];

    // Initialize the count array with 0
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the array with sorted values
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}