#include <iostream>
#include <queue>

int main()
{
    // Create a queue of integer type 
    std::queue<int> number_queue;

    // Create a queue of string type 
    std::queue<std::string> animal_queue;

    number_queue.push(1);
    number_queue.push(4);
    number_queue.push(2);


    animal_queue.push("Dog");
    animal_queue.push("Cat");
    animal_queue.push("Owl");

    // get the frist elemenet of queue
    std::string front_str =  animal_queue.front();    
    std::cout<<"The first element of string queue is : "<<front_str<<std::endl;    
    // get the last element of queue
    std::string back_str =  animal_queue.back();    
    std::cout<<"The last element of string queue is : "<<back_str<<std::endl;    

    

    // get the frist elemenet of queue
    int front_int = number_queue.front();
    std::cout<<"The last element of integer queue is : "<<front_int<<std::endl;    

    // get the last element of queue
    int back_int = number_queue.back();
    std::cout<<"The last element of integer queue is : "<<back_int<<std::endl;    


    // get the size of the queue
    int size_str = animal_queue.size();
    std::cout << "Size of the string queue: " << size_str<<std::endl;
    
    int size_int = number_queue.size();
    std::cout << "Size of the integer queue: " << size_int<<std::endl;


    std::cout<<"Integer queue: ";
    //print element of queue
    //loop until queue is empty
    while(!number_queue.empty())
    {
        // print always first element
        std::cout<<number_queue.front()<<" ";

        // remove the element the first element
        number_queue.pop();
    }std::cout<<std::endl;
    

    std::cout<<"String queue: ";
    //print element of queue
    //loop until queue is empty
    while(!animal_queue.empty())
    {
        // print always first element
        std::cout<<animal_queue.front()<<" ";

        // remove the element the first element
        animal_queue.pop();
    }std::cout<<std::endl;






    return 0;
}

//                                           C++ Queue Methods
//                      Methods	                                    Description
//                      push()	                                    Inserts an element at the back of the queue.
//                      pop()	                                    Removes an element from the front of the queue.
//                      front()	                                    Returns the first element of the queue.
//                      back()	                                    Returns the last element of the queue.
//                      size()	                                    Returns the number of elements in the queue.
//                      empty()	                                    Returns true if the queue is empty.
