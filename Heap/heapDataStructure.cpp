// Max and Min Heap Property Implementation Using Vector (Max-Heap Demonstration)

#include <iostream>
#include <vector>

// Function declarations
void swap(int *a, int *b){
    // swaping the values with temporary value
   int temp = *a;
   *a = *b;
   *b = temp;
}                             // Swap two integer values via pointers
void heapify(std::vector<int>& tree, int index);       // Restore max-heap property from a given index downwards
void insert(std::vector<int>& tree, int NewNum);       // Insert a new element into the max-heap
void printArray(std::vector<int>& tree);               // Print the contents of the heap as an array
void deleteNode(std::vector<int>& tree, int TodeleteNum); // Remove a specified element from the heap

int main()
{
    // Initialize an empty vector to represent the heap
    std::vector<int> heapTree;

    // Insert elements into the heap (bubble-up approach)
    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    // Display the heap after insertions
    std::cout << "Max-Heap array: ";
    printArray(heapTree);

    // Delete a specified value (4) and maintain the heap property
    deleteNode(heapTree, 4);
    std::cout << "After deleting an element: ";
    printArray(heapTree);

    return 0;
}
