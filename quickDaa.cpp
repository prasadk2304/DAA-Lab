#include <iostream>
using namespace std;

// Function declarations
void quick(int arr[], int lw, int up);
int partition(int arr[], int lw, int up);

int main() {
    // Array initialization
    int arr[] = {12, 85, 69, 74, 25, 65, 71, 692};
    int n = 8, i;

    // Display unsorted array
    cout << "The unsorted array is : ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Perform quicksort
    quick(arr, 0, n - 1);

    // Display sorted array
    cout << "\nThe sorted array is : ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform quicksort
void quick(int arr[], int lw, int up) {
    int pvtloc;
    // Base case: If lower bound is greater than or equal to upper bound, return
    if (lw >= up)
        return;
    // Partition the array
    pvtloc = partition(arr, lw, up);
    // Recursively sort the left sub-array
    quick(arr, lw, pvtloc - 1);
    // Recursively sort the right sub-array
    quick(arr, pvtloc + 1, up);
}

// Function to partition the array
int partition(int arr[], int lw, int up) {
    int temp, i, j, pivot;
    i = lw + 1;
    j = up;
    pivot = arr[lw];
    while (i <= j) {
        // Move i to the right until it finds an element greater than pivot
        while ((arr[i] < pivot) && (i < up)) {
            i++;
        }
        // Move j to the left until it finds an element smaller than pivot
        while (arr[j] > pivot) {
            j--;
        }
        // Swap elements if i is less than j
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        } else {
            i++;
        }
    }
    // Move pivot to its correct position
    arr[lw] = arr[j];
    arr[j] = pivot;
    // Return the pivot position
    return j;
}
