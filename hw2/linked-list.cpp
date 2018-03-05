#include<iostream>
#include<stdlib.h> //for using the exit() function
using namespace std;

class chunk {
    public:
        int value;
        chunk* next;
        chunk() {
            value =  0;
            next = NULL;
        }
};

class linkedList {
    public:
        int length;
        chunk* head;
        chunk* tail;
        linkedList() {
            length = 0;
            head = NULL;
            tail = NULL;
        }
    void insertAtHead(int x) {

    }
    void insertAtPosition(int position, int value) {

    }
    void removeFromPosition(int position) {

    }
    void displayContents() {

    }
    void deleteFirstInstance(int value) {
        //search the linked list for the value and delete it
    }
    void deleteAllInstances(int value) {
        //search the list.  Keep a list of the positions
        //delete the first position in the list (they should be in order
        //by the way you collect them)
        //once deleted, pop the first index off and reduce the others by 1,
        //as the list will have reduced in size and they will no longer be
        //valid
    }
};

int main() {

}
