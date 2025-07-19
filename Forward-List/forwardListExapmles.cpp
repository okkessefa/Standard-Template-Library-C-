#include <iostream>
#include <forward_list>

int main(){

    // Create an integer forward List
    std::forward_list<int> intteger_forward_list {1,3,2,5,4};

    // create a string forward list
    std::forward_list<std::string> string_forward_list {"Crual", "Naive", "Interactive", "Charming", "Affectionate"};

    // print the forword list by ranged loop
    std::cout<<"Integer forward list: ";
    for(const int& number : intteger_forward_list){
        std::cout<<number<< " ";
    }

    std::cout<<std::endl;
    
    std::cout<<"String forward list: ";
    for(const std::string& val : string_forward_list){
        std::cout<<val<<" ";
    }

    

    return 0;
}
/*
Forward Lists Methods
Some of the most common methods used with forward lists are listed below:

        Functions 	          Description
        
        front()	              Access the front element. 
        push_front()	      Add an element to the start of the list.
        insert_after() 	      Add an element at the position right after the given position.
        assign()	          Assign new contents to the list by replacing the current contents.
        pop_front()	          Remove the element at the front.
        remove()	          Remove elements with specific values.
        clear()	              Delete all the contents of the list.
*/