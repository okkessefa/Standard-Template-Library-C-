#include <iostream>
#include <vector>

int main(){
    
    // Initialize vector of int type
    std::vector<int> numbers {1, 100, 10, 70, 100};

    // Print the vector
    std::cout<<"Numbers ";
    for(auto& number : numbers){
        std::cout<<number<<" ";
    }
    
    return 0;
}

