#include <iostream>
#include <vector>

int main(){

    // Initialize vector of int type
    std::vector<int> numbers {1,2,3,4,5};

    //Initialize vector iterator to point to the first element
    std::vector<int>::iterator itr = numbers.begin();
    std::cout<<"First element: "<< *itr << " "<<std::endl;

    // change iterator to point to the last element
    itr = numbers.end() -1;
    std::cout<<"Last Element: "<< *itr;

    return 0;
}