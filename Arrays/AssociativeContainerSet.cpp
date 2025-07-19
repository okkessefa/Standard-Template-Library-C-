#include <iostream>
#include <set>

int main(){

    // Initialize set of int type
    // Set prevent the usage of dublicating number
    // and sorted version
    std::set<int> numbers {1, 100, 10, 70, 100};

    // Print numbers
    std::cout<<"Numbers :";
    for(auto& number : numbers){
        std::cout<<number<<" ";
    }

    return 0;
}

