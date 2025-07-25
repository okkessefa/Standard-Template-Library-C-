#include <iostream>

// Function to maintain the heap property (max-heap)
// Arguments:
// - HeapArray: the array representing the heap
// - size: current size of the heap
// - index: index to heapify from (typically root or subtree root)
void heapify(int HeapArray[], int size, int index) {
    int largest = index;                 // Assume current index is the largest
    int left = 2 * index + 1;            // Left child index
    int right = 2 * index + 2;           // Right child index

    // Check if left child exists and is greater than the current largest
    if (left < size && HeapArray[left] > HeapArray[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than the current largest
    if (right < size && HeapArray[right] > HeapArray[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and recursively heapify
    if (largest != index) {
        std::swap(HeapArray[index], HeapArray[largest]);
        heapify(HeapArray, size, largest);  // Heapify the affected subtree
    }
}

// Function to perform heap sort
// Step 1: Build a max-heap from the array
// Step 2: Extract elements from the heap one by one
void heapsort(int HeapArray[], int size) {
    // Build the max heap (start from last non-leaf node)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(HeapArray, size, i);
    }

    // Extract elements from heap one by one (heap sort)
    for (int i = size - 1; i >= 0; i--) {
        std::swap(HeapArray[0], HeapArray[i]);   // Move current root to end
        heapify(HeapArray, i, 0);                // Restore max-heap for reduced size
    }
}

// Function to print the array
void printarray(int HeapArray[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << HeapArray[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Sample array to be sorted
    int arr[] = {1, 12, 9, 5, 6, 10, 47, 23, 13};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate size of the array

    // Perform heap sort
    heapsort(arr, n);

    // Display the sorted array
    std::cout << "Sorted array is \n";
    printarray(arr, n);

    return 0;
}
