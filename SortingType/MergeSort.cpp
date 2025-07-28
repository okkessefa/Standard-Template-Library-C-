#include <iostream>

void Merge(int Array[], int left, int right, int mid);
void MergeSort(int Array[], int left, int right){
    if(left < right){// continue to divide the array until being one element
        int mid = left + (right - left) / 2; // Finding the order of middle elemeent

        // Recursivly  getting left and right part
        MergeSort(Array, left, mid); // left part
        MergeSort(Array, mid + 1,  right); // right part
        Merge(Array, left, mid, right); // When all elelements are just one element merge them into one array

    }
}
void PrintArray(int Array[], int size);

int main(){

}


// Driver program
int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  MergeSort(arr, 0, size - 1);
  std::cout << "Sorted array: \n";
  PrintArray(arr, size);
  return 0;
}