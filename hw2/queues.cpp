#include<iostream>
#include<stdlib.h> //for using the exit() function
using namespace std;

class chunk {
    public:
        int value;
        chunk* next;
        chunk() {
            value = 0;
            next = NULL;
        }
};

class Queue {
    public:
        int size;
        chunk* head;
        chunk* tail;
        Queue() {
            size = 0;
            head = NULL;
            tail = NULL;
        }
    void enqueue(int x) {
        chunk* temp = new chunk;
        temp->value = x;
        if(size == 0) {
            head = tail = temp; //set everything to the one chunk
        }
        else {
            temp->next = head; //point new chunk at head
            head = temp; //make the new chunk the head
        }
        size++;
    }
    void dequeue() {
        if(size == 0) {
            cout << "Sorry, there's nothing to delete..." << endl;
            return;
        }
        else {
            chunk* traverse;
            traverse = head;
            while(traverse->next != tail) { //using tail pointer
                traverse = traverse->next; //could also do with 2 pointers, one lagging
            }
            traverse->next = NULL; //TODO: make this better, I think it can be shortened
            delete tail;
            tail = traverse;
            size--;
        }
    }
    void printContents() {
        chunk* traverse;
        traverse = head;
        while(traverse != NULL) {
            cout << traverse->value << endl;
            traverse = traverse->next;
        }
        cout << "Value of tail: " << tail->value << endl;
    }
};

int main() {
    int choice, value;
    Queue object;
    while(1) {
        cout << "Press 1 to add to the queue" << endl;
        cout << "Press 2 to delete from the queue" << endl;
        cout << "Press 3 to display" << endl;
        cout << "Anything else to quit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Add what?" << endl;
                cin >> value;
                object.enqueue(value);
                break;
            case 2:
                object.dequeue();
                break;
            case 3:
                object.printContents();
                break;
            default:
                exit(1);
        }
    }
}