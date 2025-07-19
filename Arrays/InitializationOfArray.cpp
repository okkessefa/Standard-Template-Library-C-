// #include <array>

// // declaration of std::array 
// std::array<T, N> array_name;


#include <iostream>
#include <array>

int main(){
    // Uniform initialization
    std::array<int, 5> numbers {1, 2, 3, 4, 5};

    // Acces first array element
    std::cout<< numbers[0]; // return 1  
    
    // Acces first array element
    std::cout<< numbers[1]; // return 2

    // std::cout << numbers.at(10); // throws std::out_of_range exception

    std::array<int, 5> marks = {50, 67, 88, 98, 34};
    // Modify 3rd element usinbg []
    marks[2] = 76;

    // modify the first element using at
    marks.at(0) = 54;



    std::cout<< " The elements are: ";
    //use a ranged for loop print the elements
    for(const int num : numbers){
        std::cout<<num<<" ";
    } 

    std::cout<<" The size of array: "<< numbers.size() << std::endl;

    if(!marks.empty()){
        std::cout<<"This array is not empty"<<std::endl;
    }
    else{
        std::cout<<"This array is empty"<<std::endl;
    }

    return 0;
}

// Accessing the Elements of std::array

