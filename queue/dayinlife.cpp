#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

class Customer {
    public:
        int inTime; //Time they got into the store
        int outTime; //Time they left the store
        int placesOrder; //Time they got to place their order at
        int orderTime; //random number between 1 and 6 minutes
    
    Customer() {

    }
};

class Queue {
    public:
        Customer *head, *tail;
    //void enqueue() -- > add a new customer
    //void dequeue() -- > remove a customer
    //int getLength() -- > get the length of the queue
};

class Stack {
    //might want to have a stack of customers who have left the store to calculate
    // either that or keep a global total of waiting time and number of customers
};

int main() {
    int time = 0;
    //simulate starting 8 am through 1 am.
    //this is 1020 minutes
    while(time < 1020) {
        //simulate
        //1. Someone walks in (adding to the queue)

        //2. Someone is done, and will walk out with their food (removing from the queue)
    }
}