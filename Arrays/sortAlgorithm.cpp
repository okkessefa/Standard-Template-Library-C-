#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    
    // Initialize vector of int type
    std::vector<int> numbers {3,5,1,4,2};

    // Sort vector elements in ascending order
    std::sort(numbers.begin(), numbers.end());
    
    // Print the sorted vectors
    for(int number : numbers){
        std::cout<<number<<" ";
    }
    
    
    return 0;
}