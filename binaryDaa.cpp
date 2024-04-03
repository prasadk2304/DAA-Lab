#include<iostream>
using namespace std;

// Function to perform binary search in a sorted array
// Parameters:
//   array: The sorted array to search in
//   x: The element to search for
//   low: The lowest index in the current search range
//   up: The highest index in the current search range
// Returns:
//   The index of the element if found, otherwise -1
int binarySearch(int array[], int x, int low, int up) {
    // Check if the upper bound is greater than or equal to the lower bound
    if (up >= low) {
        // Calculate the middle index
        int mid = low + (up - low) / 2;
        // If the element is found at the middle index
        if (array[mid] == x)
            return mid;
        // If the element is smaller than the element at the middle index, search in the left half
        if (array[mid] > x)
            return binarySearch(array, x, low, mid - 1);
        // If the element is larger than the element at the middle index, search in the right half
        return binarySearch(array, x, mid + 1, up);
    }
    // If the element is not found within the search range
    return -1;
}

int main() {
    // Initialize the array
    int array[10] = {3, 5, 2, 1, 8, 7, 6, 4, 9};
    // Calculate the size of the array
    int n = sizeof(array) / sizeof(array[0]);
    int x;
    // Prompt user to enter the element to search
    cout << "\nEnter the element to search :";
    cin >> x;
    // Perform binary search and store the result
    int result = binarySearch(array, x, 0, n - 1);
    // If the element is not found, print "Not found"
    if (result == -1)
        cout << "\nNot found";
    // If the element is found, print its index
    else
        cout << "\nElement is found at index :" << result;
}
