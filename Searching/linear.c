#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements from the user
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;

    // Get the target element from the user
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int ans = linearSearch(arr, n, target);

    if (ans != -1) {
        printf("Element %d found at index %d.\n", target, ans);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}