#include <iostream>
#include <vector>


void Merge(std::vector<int> &Array, int left, int mid, int right){
     // initialize the control pointer
    int n1 = mid - left + 1;
    int n2 = right - mid ;

    if (n1 <= 0 || n2 <= 0) {
        std::cerr << "Invalid subarray size\n";
        return;
    }

     // Creating Temporary Containers
    std::vector<int> L(n1); 
    std::vector<int> M(n2);

    //  getting left and right part of array into two piece of array
    for(int i = 0; i < n1; i++){
        L[i] = Array[left + i];
    }
    for(int j = 0; j < n2; j++){
        M[j] = Array[mid + 1 + j];
    }

    // Re-set the controller to re-placement
    int i = 0; int j = 0 ; int k = left;

    while(i<n1 && j<n2){
        if(L[i] <= M[j]){
            Array.at(k) = L.at(i);
            i++; k++;
        }else{
            Array.at(k) = M.at(j);
            j++; k++;
        }
    }// Adding  the elements that if there is reminded element in any container
    while(i<n1){
        Array.at(k) = L.at(i);
        i++; k++;
    }
    while(j<n2){
        Array.at(k) = M.at(j);
        j++; k++;
    }
    // Delete after finishing the re-initalize the variables
    
}
void MergeSort(std::vector<int> &Array, int left, int right){
    if(left < right){// continue to divide the array until being one element
        int mid = left + (right - left) / 2; // Finding the order of middle elemeent

        // Recursivly  getting left and right part
        MergeSort(Array, left, mid); // left part
        MergeSort(Array, mid + 1,  right); // right part
        Merge(Array, left, mid, right); // When all elelements are just one element merge them into one array

    }
}
void PrintArray(std::vector<int> &Array, int size){
    for (int i = 0; i< size ; i++)
        std::cout<<Array[i] <<" ";
    std::cout<<std::endl;
}



// river program
int main() {
    std::vector<int> Array = {6, 5, 12, 10, 9, 1};
    //int size = sizeof(Array)/sizeof(Array[0]);
    int size = Array.size(); 
    MergeSort(Array, 0, size - 1);
    std::cout << "Sorted array: \n";
    PrintArray(Array, size);
    return 0;
}