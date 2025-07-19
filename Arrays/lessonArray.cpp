#include <iostream>
#include <vector>

int main(){
    // create  vector of int tyoe
    std::vector<int> numbers {1,2,3,4,5};

    //print cevtor elements using ranged loop
    for(int i = 0; i<numbers.size(); i++){
        std::cout<< numbers[i] << " ";
    }
    return 0;

}

// Method 2:

// vector<int> vector3(5, 12);
// Here, 5 is the size of the vector and 12 is the value.

// This code creates an int vector with size 5 and initializes the vector with the value of 12. So, the vector is equivalent to

// vector<int> vector3 = {12, 12, 12, 12, 12};

// C++ Vector Functions
// In C++, the vector header file provides various functions that can be used to perform different operations on a vector.

// Function	Description
// size()	returns the number of elements present in the vector
// clear()	removes all the elements of the vector
// front()	returns the first element of the vector
// back()	returns the last element of the vector
// empty()	returns 1 (true) if the vector is empty
// capacity()	check the overall size of a vector



// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//   vector<int> num {1, 2, 3, 4, 5};

//   // declare iterator
//   vector<int>::iterator iter;

//   // use iterator with for loop
//   for (iter = num.begin(); iter != num.end(); ++iter) {
//     cout << *iter << "  ";
//   }

//   return 0;
// }