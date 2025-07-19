#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>


int main(){

    std::array<int , 5> age {45, 23, 66, 87, 21};

    //Sorting
    std::sort(age.begin(), age.end());

    // print the sorted version
    std::cout<<"The the sorted array: ";

    for(const int elt : age){
        std::cout<<elt << " ";
    }
    std::cout<<std::endl;

    // Searching
    //Checking whether the number 5 exist or not
    auto found = std::find(age.begin(), age.end(), 5);
    if(found != age.end()) std::cout<<"5 was found"<<std::endl;
    else std::cout<<"5 was not found"<<std::endl;

    //summing
    int sum = std::accumulate(age.begin(), age.end(), 0);
    std::cout<<"The sum of the element of array is : "<< sum <<std::endl;

    return 0;
}