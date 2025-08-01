#include <iostream>
#include <vector>
#include <chrono> // for timing
#include <algorithm> // For std::generate
#include <random>

void swapelement(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sorting algorithms
int partition(std::vector<int>& arr, int leftmostindex, int rightmostindex){
    int pivot = arr[leftmostindex];
    int i = leftmostindex;
    int j = rightmostindex;

    while(i< j){
        do{
            i++;
        }while(i < rightmostindex && arr[i] <= pivot);
        do{
            j--;
        }while(j > leftmostindex && arr[j] > pivot);
        if(i < j){
            swapelement(&arr[i], &arr[j]);
        }
    }
    swapelement(&arr[leftmostindex], &arr[j]);
    
    return j;


}
void quicksort(std::vector<int>& arr, int left, int right){
    if(left< right){
        int pi = partition(arr, left, right);

        quicksort(arr, left, pi);
        quicksort(arr, pi + 1, right);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right){

    int n1 =  mid - left +1;
    int n2 = right - mid; 

    if (n1 <= 0 || n2 <= 0) {
        std::cerr << "Invalid subarray size\n";
        return;
    }

    std::vector<int> L(n1);
    std::vector<int> M(n2);

    for(int i = 0; i<n1; i++){
        L[i] = arr[left + i];
    }

    for(int j = 0; j<n2; j++){
        M[j] = arr[mid + 1+ j];
    }

    int i = 0; int j = 0; int k = left;
    while((i < n1) && (j < n2)){
        if(L[i] < M[j]){
            arr.at(k) = L.at(i);
            i++; k++;
        }else{
            arr.at(k) = M.at(j);
            j++; k++;
        }
    }
    while(i<n1){
        arr.at(k) = L.at(i);
        i++; k++;
    }
    while(j<n2){
        arr.at(k) = M.at(j);
        j++; k++;
    }


}
void mergesort(std::vector<int>& arr, int left, int right){
    if(left<right){
        int mid = left + (right - left ) /2;
        
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left , mid, right);
    }
}

//Utility
std::vector<int> generateRandomArray(int size){

}
void benchmarkSort(const std::string& name, void(*sortfunc)(std::vector<int>&), std::vector<int> arr){

}

int main(){
    //Menu flow
     
    return 0;
}


// ----------------------MENU--------------------------

// Select sorting algorithm(s) to benchmark:
// 1. Merge Sort
    // Enter array size: 10000
// 2. Quick Sort
    // Enter array size: 10000
// 3. All of them
    // Enter array size: 10000
// 4. Quit


// Generating random array...
// Benchmarking...
//  -------------------------------------------------

// Output Sample
// Benchmark Results (Array size: 10000)

// Bubble Sort     : 532.124 ms
// Merge Sort      :   3.427 ms
// Quick Sort      :   4.112 ms

// Fastest: Merge Sort
