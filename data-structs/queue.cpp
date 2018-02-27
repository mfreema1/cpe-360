#include<iostream>
using namespace std;
//All you really have to do with a queue is add and subtract from opposite ends

class chunk {
    public:
        int value;
        chunk* next;

        chunk() {
            value = 0;
            next = NULL;
        }
};

//queue of chunks
class Queue {
    public:
        chunk* head;

        Queue() {
            head = NULL;
        }
    
    //1.  ADD
    void enqueue(int x) {

    }

    //2. DELETE
    void dequeue() {
        chunk *temp, *target;
        if(head == NULL) {

        }
        else if(head->next == NULL) { //if the queue is only one element long

        }
        else {
            target = head;
            while(target->next != NULL) {
                temp = target;
                target = target->next;
            }
            temp->next = NULL;
            delete target; //keep in mind this won't work if we have one thing in the queue
        }
    }

    //3. DISPLAY, the same as all other data structures
    void display() {

    }
};

int main() {

}