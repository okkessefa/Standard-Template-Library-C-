// Max and Min Heap Property Implementation Using Vector (Max-Heap Demonstration)

#include <iostream>
#include <vector>

// Function declarations
void swapfunc(int *a, int *b){
    // swaping the values with temporary value
   int temp = *a;
   *a = *b;
   *b = temp;
}                             // Swap two integer values via pointers
void heapify(std::vector<int>& tree, int& size, int index){       // Restore max-heap property from a given index downwards
    // Initialize the variable
    int largest = index;
    // if a node is stored an index k, then its left child is stored at index 2k + 1 and its right child at index 2k + 2
    int left = 2*index +1;
    int right = 2* index +2;

    if( (left < size) && (tree[left] > tree[largest]) ) {largest = left;}
    if( (right < size) && (tree[right] > tree[largest]) ) {largest = right;}
    if(largest != index){swapfunc(&tree[index], &tree[largest]); heapify(tree, size,largest);}
}
void insert(std::vector<int>& tree, int& size, int NewNum){       // Insert a new element into the max-heap
    tree.push_back(NewNum);
    size++;
    int current = size - 1;

    // Control for whether the element is positioned correctly
    while(current > 0){
        // Tempoarary value for checking the value position with refernce
        int parent = (current - 1) / 2;
        // The value of each node is less than or equal to the value of its parent, with the maximum value at the root
        if(tree[current] > tree[parent]){
            swapfunc(&tree[current], &tree[parent]);
            current = parent;
        }else{
            break;
        }
    }

}
void printArray(std::vector<int>& tree){               // Print the contents of the heap as an array
    for(const int num : tree) {std::cout<<num<<" "; } std::cout<<std::endl;
}
void deleteNode(std::vector<int>& tree, int& size, int TodeleteNum) {
    // Return immediately if the heap is empty
    if (size == 0) return;

    int i;
    // Search for the index of the element to be deleted
    for (i = 0; i < size; i++) {
        if (TodeleteNum == tree[i]) break;
    }

    // Swap the found element with the last element in the heap
    // (Assumes swapfunc correctly swaps values via pointers)
    swapfunc(&tree[i], &tree[size - 1]);

    // Decrease the logical heap size to reflect removal
    size--;

    // Remove the last element physically from the vector
    tree.pop_back();

    // Re-heapify the entire heap to restore the max-heap property
    // Note: This is O(n log n). For better performance, consider heapify only from index i
    for (int k = 0; k < size; k++) {
        heapify(tree, size, k);
    }
}
int main()
{
    // Initialize an empty vector to represent the heap
    std::vector<int> heapTree;
    int heapSize = 0;

    insert(heapTree, heapSize, 3);
    insert(heapTree, heapSize, 9);
    insert(heapTree, heapSize, 2);
    insert(heapTree, heapSize, 1);
    insert(heapTree, heapSize, 4);
    insert(heapTree, heapSize, 5);
    insert(heapTree, heapSize, 7);

    std::cout << "Max-Heap array: ";
    printArray(heapTree);

    std::cout << "For loop is working\n";

    deleteNode(heapTree, heapSize, 4);

    std::cout << "deleting process is working\n";
    std::cout << "Tree size: " << heapSize << "\n";

    std::cout << "After deleting an element: ";
    printArray(heapTree);

    return 0;
}
