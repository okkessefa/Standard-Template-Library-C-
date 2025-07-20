#include <iostream>
#include <forward_list>

int main(){

    // Create an integer forward List
    std::forward_list<int> integer_forward_list {1,3,2,5,4};

    // create a string forward list
    std::forward_list<std::string> string_forward_list {"Crual", "Naive", "Interactive", "Charming", "Affectionate"};

    // print the forword list by ranged loop
    std::cout<<"Integer forward list: ";
    for(const int& number : integer_forward_list){
        std::cout<<number<< " ";
    }std::cout<<std::endl;

    
    
    std::cout<<"String forward list: ";
    for(const std::string& val : string_forward_list){
        std::cout<<val<<" ";
    }std::cout<<std::endl;

    /*
    // access the first element
    int first_element_integer = integer_forward_list.front();
    
    std::string first_element_string = string_forward_list.front();

    std::cout<<"The first element of integer list: "<< first_element_integer << std::endl;
    std::cout<<"The first element of string list: "<< first_element_string << std::endl;


    string_forward_list.push_front("Honest");
    integer_forward_list.push_front(0);

    std::cout<<"String forward list after push_front(): ";
    for(const std::string& val : string_forward_list){
        std::cout<<val<<" ";
    }std::cout<<std::endl;

    std::cout<<"Integer forward list after push_front(): ";
    for(const int& number : integer_forward_list){
        std::cout<<number<< " ";
    }std::cout<<std::endl;

    // point iterator to the 2nd position of the forward list
    auto int_itr = integer_forward_list.begin();
    std::advance(int_itr, 1);

    auto string_itr = string_forward_list.begin();
    std::advance(string_itr, 1);


    // insert integer element at the 3rd position
    integer_forward_list.insert_after(int_itr, 6);

    // insert string element at the 3rd position
    string_forward_list.insert_after(string_itr, "Calm");

    
    std::cout<<"String forward list after insert_after(): ";
    for(const std::string& val : string_forward_list){
        std::cout<<val<<" ";
    }std::cout<<std::endl;

    std::cout<<"Integer forward list after insert_after(): ";
    for(const int& number : integer_forward_list){
        std::cout<<number<< " ";
    }std::cout<<std::endl;

    // replace the entire content of the forward list
    // with new elements 3 and 4
    integer_forward_list.assign({3, 4});

    // replace the entire content of the forward list
    // with new elements calm and charming
    string_forward_list.assign({"calm", "charming"});


    std::cout << "\nString Forward List after assign(): ";
    for (const int& element : integer_forward_list) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "\nInteger Forward List after assign(): ";
    for (const std::string& element : string_forward_list) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Deletes the first element of rgw list
    
    string_forward_list.pop_front();
    integer_forward_list.pop_front();
    
    // printing the lists after being modified
    std::cout << "\nInteger Forward List after pop_front(): ";
    for(const int& number : integer_forward_list){
        std::cout<<number<<" ";
    }std::cout<<std::endl;
    
    std::cout << "\nString Forward List after pop_front(): ";
    for(const std::string str : string_forward_list){
        std::cout<<str<<" ";
    }std::cout<<std::endl;
    
    // deletes all accurrences of the specified element from the list
    
    string_forward_list.remove("Affectionate");
    integer_forward_list.remove(4);
    
    // printing the lists after being modified
    std::cout << "\nInteger Forward List after remove(): ";
    for(const int& number : integer_forward_list){
        std::cout<<number<<" ";
    }std::cout<<std::endl;
    
    std::cout << "\nString Forward List after remove(): ";
    for(const std::string str : string_forward_list){
        std::cout<<str<<" ";
    }std::cout<<std::endl;
    
    // Deletes all the elements from the list
    string_forward_list.clear();
    integer_forward_list.clear();
    
    // printing the lists after being modified
    std::cout << "\nInteger Forward List after clear(): ";
    for(const int& number : integer_forward_list){
        std::cout<<number<<" ";
    }std::cout<<std::endl;
    
    std::cout << "\nString Forward List after clear(): ";
    for(const std::string str : string_forward_list){
        std::cout<<str<<" ";
    }std::cout<<std::endl;
    */

    return 0;
}
/*
Forward Lists Methods
Some of the most common methods used with forward lists are listed below:

        Functions 	          Description
        
✅    front()	              Access the front element. 
✅      push_front()	          Add an element to the start of the list.
✅      insert_after() 	      Add an element at the position right after the given position.
✅      assign()	              Assign new contents to the list by replacing the current contents.
✅      pop_front()	          Remove the element at the front.
        remove()	           Remove elements with specific values.
        clear()	               Delete all the contents of the list.
*/