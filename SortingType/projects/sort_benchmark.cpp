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
void iterativeMergeSort(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> buffer(n);  // Shared buffer for all merge steps

    // Outer loop: grow merge width from 1, 2, 4, 8, ...
    for (int width = 1; width < n; width *= 2) {
        // Inner loop: merge adjacent blocks of size 'width'
        for (int i = 0; i < n; i += 2 * width) {
            int left = i;
            int mid = std::min(i + width, n);
            int right = std::min(i + 2 * width, n);

            // Merge arr[left:mid] and arr[mid:right] into buffer
            int i1 = left;
            int i2 = mid;
            int k = left;

            while (i1 < mid && i2 <= right) {
                if (arr[i1] <= arr[i2]) {
                    buffer[k++] = arr[i1++];
                } else {
                    buffer[k++] = arr[i2++];
                }
            }

            // Copy any remaining elements
            while (i1 < mid) buffer[k++] = arr[i1++];
            while (i2 < right) buffer[k++] = arr[i2++];

            // Copy merged part back to original array
            for (int j = left; j < right; ++j) {
                arr[j] = buffer[j];
            }
        }
    }
}


//Utility
std::vector<int> generateRandomArray(int size){
    std::vector<int> array(size);

    // Create a random number generator between 0 to size times 10 (to be obtain more wived range) 
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
        iterativeMergeSort(v);
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
