#include<iostream>
using namespace std;

// Function declarations
void merges(int a[], int l, int up);
void merge(int arr[], int temp[], int l1, int up1, int l2, int up2);
void copy(int arr[], int temp[], int low, int up);

int main() {
    // Array initialization
    int a[7] = {2, 33, 54, 6, 87, 11, 12};
    int n = 7, i;

    // Perform mergesort
    merges(a, 0, n - 1);

    // Display unsorted array
    cout << "The unsorted array is : ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    // Display sorted array
    cout << "\nThe sorted array is : ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

// Function to perform mergesort
void merges(int a[], int l, int up) {
    int mid;
    int temp[10];
    // Base case: If lower bound is less than upper bound
    if (l < up) {
        mid = (l + up) / 2;
        // Recursively sort the left half
        merges(a, l, mid);
        // Recursively sort the right half
        merges(a, mid + 1, up);
        // Merge the sorted halves
        merge(a, temp, l, mid, mid + 1, up);
        // Copy the merged elements to the original array
        copy(a, temp, l, up);
    }
}

// Function to merge two sorted subarrays
void merge(int arr[], int temp[], int l1, int up1, int l2, int up2) {
    int i = l1;
    int j = l2;
    int k = l1;

    // Merge elements while both subarrays have elements
    while ((i <= up1) && (j <= up2)) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements from the first subarray
    while (i <= up1)
        temp[k++] = arr[i++];

    // Copy remaining elements from the second subarray
    while (j <= up2)
        temp[k++] = arr[j++];
}

// Function to copy elements from temporary array to original array
void copy(int arr[], int temp[], int low, int up) {
    int i;
    for (i = low; i <= up; i++) {
        arr[i] = temp[i];
    }
}
