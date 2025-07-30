#include <iostream>
#include <vector>

//Initiaalize the functions to quick Sort
void numberSwap(int& first, int& second);
void partition(std::vector<int>& List, int leftmostIndex, int rightmostIndex);
void quickSort(std::vector<int>& List, int leftmostIndex, int rightmostIndex);
void DisplayList(std::vector<int>& List);


int main(){

    std::vector<int> Numbers = {3,7,12,8,5,6,10,1,16,4};
    int sizeList = Numbers.size();

    // There are two display function that are called to observe differencies
    //      before and after the list  
    std::cout << "Unsorted Array: \n";
    DisplayList(Numbers);
    
    // perform quicksort on data
    quickSort(Numbers, 0, sizeList - 1);
    
    std::cout << "Sorted array in ascending order: \n";
    DisplayList(Numbers);



    return 0;
}