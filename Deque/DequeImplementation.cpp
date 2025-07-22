#include <iostream>

#define MAX 10 // Maximum capability of the underlying array

class Deque
{
    int arr[MAX]; // Fixed-size array to store deque elements
    int front; // Index of front element
    int rear; // Index of rear element
    int size; // Maximum number of element allowed(user-defined)


public:
    // Constructor: initizlize an empty deque qith given size
    Deque(int size)
    {
        front = -1; // -1 iindicates empty deque
        rear = 0;
        this->size = size;
    }
    // Core opeartions
    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();

    // state checkers
    bool isFull();
    bool isEmpty();

    // accessors
    int getFront();
    int getRear();
};
// Check wheether the deque is full 
bool Deque::isFull(){
    // Case 1 : front at 0 and rear at last index (full linear)
    // Case 2 :  front is one position ahead of rear (full circulary)
    return ((front == 0 && rear == size -1) || front == rear + 1);
}
// check whether the deque is empty
bool Deque::isEmpty(){
    return (front == -1);
}
// Insert an element at the front of the deque
void Deque::insertfront(int key){
    if(isFull()) {std::cout<<"Overflow\n"<<std::endl; return;}
    // First element insertion
    if(front == -1) {front = 0; rear = 0;}
    // Circularly wrap-around if front is at 0
    else if(front == 0) {front = size - 1;} 
    else {front -= 1;}
    arr[front] = key; // Store the element
}
// Insert an element at the rear of the deque
void Deque::insertrear(int key){
    if(isFull()) {std::cout<<"Overflow\n"<<std::endl; return;}
    // First element insertion
    if(front == -1) {front = 0; rear = 0;}
    // Circullarly wrap-around if the rear is at end 
    else if(rear == size -1) {rear = 0;}
    else { rear +=1;}
    arr[rear] = key; // Store the element
}
// Delete an element from the front of the deque
void Deque::deletefront(){
    if(isEmpty()) {std::cout<<"Underflow\n"<<std::endl; return;}
    // Sigle element case
    if(front == rear) { front = -1; rear = -1;}
    // Circularly wrap-around 
    else if(front  == size -1) {front = 0;}
    else {front += 1;}
}
// Delete an element from the rear of the deque
void Deque::deleterear(){
    if(isEmpty()) {std::cout<<"Underflow\n"<<std::endl; return;}
    // Single element case
    if(front == rear) { front = -1 ; rear = -1;}
    // Circularly wrap-around
    else if(rear == 0) {rear = size-1;}
    else {rear -= 1;}
    
}
// Return the front element
int Deque::getFront(){
    if(isEmpty()) {std::cout<<"Underflow\n"<<std::endl; return -1;}
    return arr[front];
}
// Return the rear element
int Deque::getRear(){
    if(isEmpty()) {std::cout<<"Underflow\n"<<std::endl; return -1;}
    return arr[rear];
}

// Test the deque implementation
int main(){
    Deque dq(4); // Create a deque of size 4

    std::cout << "insert element at rear end \n";
    dq.insertrear(5);
    dq.insertrear(11);

    std::cout << "rear element: "<< dq.getRear() << std::endl;

    dq.deleterear();
    std::cout << "after deletion of the rear element, the new rear element: " << dq.getRear() << std::endl;

    std::cout << "insert element at front end \n";

    dq.insertfront(8);

    std::cout << "front element: " << dq.getFront() << std::endl;

    dq.deletefront();

    std::cout << "after deletion of front element new front element: " << dq.getFront() << std::endl;

    return 0;
}