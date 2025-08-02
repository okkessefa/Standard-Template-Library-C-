#include <iostream>
#include <vector>
#include <chrono> // for timing
#include <algorithm> // For std::generate
#include <random>
#include <functional>

// swap function with classic method
void swapelement(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sorting algorithms

// 1-> Quick Sort
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
            swapelement(&List[i], &List[j]);
        }
    }

    // Place the pivot element at its correct position
    swapelement(&List[leftmostIndex], &List[j]);

    // Return the partition index
    return j;
}

// Recursive QuickSort function using Hoare’s partitioning scheme
void quicksort(std::vector<int>& List, int leftmostIndex, int rightmostIndex){
    if(leftmostIndex < rightmostIndex){    
        // Partition the array and get the pivot index
        int pi = partition(List, leftmostIndex, rightmostIndex);
        
        // Recursively apply quicksort to the left subarray
        quicksort(List, leftmostIndex, pi);

        // Recursively apply quicksort to the right subarray
        quicksort(List, pi + 1, rightmostIndex);
    }
}

// 2-> Merge Sort
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
void mergesort(std::vector<int> &Array, int left, int right){
    if(left < right){// continue to divide the array until being one element
        int mid = left + (right - left) / 2; // Finding the order of middle elemeent

        // Recursivly  getting left and right part
        mergesort(Array, left, mid); // left part
        mergesort(Array, mid + 1,  right); // right part
        Merge(Array, left, mid, right); // When all elelements are just one element merge them into one array

    }
}

//Utility
std::vector<int> generateRandomArray(int size){
    std::vector<int> array(size);

    // Create a random number generator between 0 to 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size  * 10);

    // Initialize vector elements with random values
    for (int& value : array)
        value = dis(gen);
    return array;
}
// Measuring Time
int benchmarkSort(const std::function<void(std::vector<int>&)>& sortfunc, std::vector<int> arr)
{
    // Get starting timepoint
    auto start = std::chrono::high_resolution_clock::now();
    // Call the function, here sort()
    sortfunc(arr);
    // Get ending timepoint
    auto finish = std::chrono::high_resolution_clock::now();

    // Get duration. Substart timepoints to 
    // get duration. To cast it to proper unit
    // use duration cast method
    // To get the value of duration use the count()
    return std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count();
}

void runBenchmark(const std::function<void(std::vector<int>&)>& sortFunc, const std::string& label, int& size)
{
    std::vector<int> arr = generateRandomArray(size);
    int duration = benchmarkSort(sortFunc, arr);
    std::cout<<"<------------------------------------------------------------------>"<<std::endl;
    std::cout<<label<<"      "<<":"<<duration<<" ms."<<std::endl;
    std::cout<<"<------------------------------------------------------------------>"<<std::endl;
}

int main(){
    //Menu flow
    int option;
    int sizeOption;

    auto merge_lambda = [](std::vector<int>& v){
        mergesort(v, 0 ,v.size() -1);
    };

    auto quick_lambda = [](std::vector<int>& a){
        quicksort(a, 0 ,a.size());
    };

    do{
        std::cout<<"<------------------------------------------------------------------>"<<std::endl;
        std::cout<<"<----------------Benchmark Sort Comparison CLI Tool---------------->"<<std::endl;
        std::cout<<"<------------------------------------------------------------------>"<<std::endl;
        std::cout<<"<----Optıon 1: Merge Sort"<<std::endl;
        std::cout<<"<----Optıon 2: Quick Sort"<<std::endl;
        std::cout<<"<----Optıon 3: All sort types"<<std::endl;
        std::cout<<"<----Optıon 4: Quit"<<std::endl;
        std::cout<<"Enter your option: ";
        std::cin>>option;
        if (option== 4){ break;}
        std::cout<<"Enter input size: ";
        std::cin>>sizeOption;
        std::cout<<"<------------------------------------------------------------------>"<<std::endl;
        std::cout<<"Generating random array..."<<std::endl;
        std::cout<<"Benchmarking..."<<std::endl;
        
        if(option == 1)
        {
            runBenchmark(merge_lambda, " Merge Sort", sizeOption); 
        }
        else if(option == 2)
        {
            runBenchmark(quick_lambda, " Quick Sort", sizeOption);    
        }
        else if(option == 3)
        {
            runBenchmark(merge_lambda, " Merge Sort", sizeOption); 
            runBenchmark(quick_lambda, " Quick Sort", sizeOption);    
        }
    }while(option != 4);
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


// Merge Sort      :   3.427 ms
// Quick Sort      :   4.112 ms

// Fastest: Merge Sort
