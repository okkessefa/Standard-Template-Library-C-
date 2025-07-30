#include <iostream>
#include <vector>

// Swap two integers using pointers
void numberSwap(int* first, int* second){
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

// Partition the array using Hoare’s partitioning scheme
// It uses the first element as pivot and rearranges the list
// such that all elements smaller than or equal to the pivot are on the left
// and all elements greater than the pivot are on the right
int partition(std::vector<int>& List, int leftmostIndex, int rightmostIndex){
    int pivot = List[leftmostIndex];    // Choosing the first element as pivot
    int i = leftmostIndex;              // Left scan index
    int j = rightmostIndex;             // Right scan index (exclusive upper bound)

    while(i < j){
        // Move i rightward until finding an element greater than the pivot
        do {
            i++;
        } while(i < rightmostIndex && List[i] <= pivot);

        // Move j leftward until finding an element less than or equal to the pivot
        do {
            j--;
        } while(j > leftmostIndex && List[j] > pivot);

        // Swap elements that are on the wrong side of the pivot
        if(i < j){
            numberSwap(&List[i], &List[j]);
        }
    }

    // Place the pivot element at its correct position
    numberSwap(&List[leftmostIndex], &List[j]);

    // Return the partition index
    return j;
}

// Recursive QuickSort function using Hoare’s partitioning scheme
void quickSort(std::vector<int>& List, int leftmostIndex, int rightmostIndex){
    if(leftmostIndex < rightmostIndex){    
        // Partition the array and get the pivot index
        int pi = partition(List, leftmostIndex, rightmostIndex);

        // Recursively apply quicksort to the left subarray
        quickSort(List, leftmostIndex, pi);

        // Recursively apply quicksort to the right subarray
        quickSort(List, pi + 1, rightmostIndex);
    }
}

// Display elements of the list
void DisplayList(std::vector<int>& List){
    for(const auto& num : List){
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main(){

    // Initialize a sample unsorted array
    std::vector<int> Numbers = {3, 7, 12, 8, 5, 6, 10, 1, 16, 4};

    // Get the size of the list
    int sizeList = Numbers.size();

    // Display the unsorted array
    std::cout << "Unsorted Array: \n";
    DisplayList(Numbers);
    
    // Sort the array using quicksort
    quickSort(Numbers, 0, sizeList);  // Note: right bound is exclusive in this design
    
    // Display the sorted array
    std::cout << "Sorted array in ascending order: \n";
    DisplayList(Numbers);

    return 0;
}
