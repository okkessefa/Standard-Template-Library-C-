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
void heapify(std::vector<int> &tree, int index){       // Restore max-heap property from a given index downwards
    // Initialize the variable
    int size = tree.size();
    int largest = index;
    // if a node is stored an index k, then its left child is stored at index 2k + 1 and its right child at index 2k + 2
    int left = 2*index +1;
    int right = 2* index +2;

    if( (left < size) && (&tree[left] > &tree[largest]) ) largest = left;
    if( (right < size) && (&tree[right] > &tree[largest]) ) largest = right;
    if(largest != index) swap(&tree[index], &tree[largest]); heapify(tree, largest);
}
void insert(std::vector<int>& tree, int NewNum){       // Insert a new element into the max-heap
    tree.push_back(NewNum);
    int current = tree.size() - 1;

    // Control for whether the element is positioned correctly
    while(current > 0){
        // Tempoarary value for checking the value position with refernce
        int parent = (current - 1) / 2;
        // The value of each node is less than or equal to the value of its parent, with the maximum value at the root
        if(tree[current] > tree[parent]){
            swap(&tree[current], &tree[parent]);
            current = parent;
        }else{
            break;
        }
    }
}
    void printArray(std::vector<int>& tree){               // Print the contents of the heap as an array
    for(const int num : tree) std::cout<<num<<" "; std::cout<<std::endl;
}
void deleteNode(std::vector<int>& tree, int TodeleteNum){ // Remove a specified element from the heap
    int size = tree.size();
    int i;
    for(i = 0; i<size; i++){
        if(TodeleteNum == tree[i]) break;
    }
    std::cout <<"For loop is working" <<std::endl;
    swap(&tree[i], &tree[size-1]);
    tree.pop_back();
    std::cout <<"deleting process is working" <<std::endl;

    size = tree.size();
    std::cout <<"Size re-initialized" <<std::endl;
    std::cout <<"Tree size:" << size<<std::endl;


    for(int i = 0; i < size; i++) {
        std::cout <<"Heapfiy re-calling time: " << i<<std::endl; 
        heapify(tree, i); 
    }
}
int main()
{
    // Initialize an empty vector to represent the heap
    std::vector<int> heapTree;

    // Insert elements into the heap (bubble-up approach)
    insert(heapTree, 3);
    insert(heapTree, 9);
    insert(heapTree, 2);
    insert(heapTree, 1);
    insert(heapTree, 4);
    insert(heapTree, 5);
    insert(heapTree, 7);

    // Display the heap after insertions
    std::cout << "Max-Heap array: ";
    printArray(heapTree);

    // Delete a specified value (4) and maintain the heap property
    deleteNode(heapTree, 4);
    std::cout << "After deleting an element: ";
    printArray(heapTree);

    return 0;
}
