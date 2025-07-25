// Priority Queue implementation in C++
// a manual implementation of a Max-Heap — a data structure that underlies the behavior of a priority queue
#include <iostream>
#include <vector>

// Function to swap position of two elements
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Function to heapify the tree
void heapify(std::vector<int> &hT, int i) {
    int size = hT.size();
  
  // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest]) largest = l;
    if (r < size && hT[r] > hT[largest]) largest = r;

  // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}

// Function to insert an element into the tree
void insert(std::vector<int> &hT, int newNum) {
    int size = hT.size();
    if (size == 0) {
        hT.push_back(newNum);
    }else{
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(hT, i);
        }
    }
}

// Function to delete an element from the tree
void deleteNode(std::vector<int> &hT, int num) {
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++) {
        if (num == hT[i])
            break;
    }
    swap(&hT[i], &hT[size - 1]);

    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(hT, i);
    }
}

// Print the tree
void printArray(std::vector<int> &hT) {
    for (int i = 0; i < hT.size(); ++i)
        std::cout << hT[i] << " ";
    std::cout << "\n";
}

// Driver code
int main() {
    std::vector<int> heapTree;
  
    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);
  
    std::cout << "Max-Heap array: ";
    printArray(heapTree);
  
    deleteNode(heapTree, 4);
  
    std::cout << "After deleting an element: ";
  
    printArray(heapTree);
}