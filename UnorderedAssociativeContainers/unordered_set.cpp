#include <iostream>
#include <unordered_set>

int main(){

    // Initialize an unordered_set of int type
    std::unordered_set<int> numbers {1, 100, 10, 70, 100};

    // Print the set
    std::cout<<"Numbers: ";
    for(auto& num : numbers){
        std::cout<<num<<" ";
    }



    return 0;
}