#include<iostream>
#include<stdlib.h> //for using the exit() function
using namespace std;

//First create the idea of a 'chunk'
class chunk {
    public:
        int value;
        chunk* next;

        chunk() {
            value = 0;
            next = NULL;
        }
};
//Second, we create the idea of a 'stack of chunks'
class Stack {
    //stack of chunks
    //three operations: add (push), delete (pop), display

    //one attribute you need:
    chunk* top; //top pointer of a stack is literally called the top pointer

    //constructor
    public:
        Stack() {
            top = NULL;
            //when you create a brand new stack, it's an empty stack,
            //meaning the top pointer must be grounded
        }

    void push(int x) {
        //purpose: add this value 'x' all the way to the front
        chunk* temp = new chunk;
        temp->value = x; //this chunk is now ready to be added to the stack
        //is my stack empty? You'll know it is if the top pointer is NULL
        if(top == NULL) {
            top = temp;
        }
        //if not, you do something else
        else {
            temp->next = top; //1
            top = temp; //2
        }
    }

    void pop() {
        //purpose: delete an element from the stack (the FIRST element and no other)
        chunk* temp;

        if(top == NULL) {
            cout << "Empty stack, nothing to delete" << endl;
        }
        else {
            temp = top; //1
            top = top->next; //2
            cout << "About to delet: " << temp->value << endl;
            delete temp;
        }
    }

    void display() {
        //this function is the same for all three of the main functions, because they are
        //inherently the same, the only real difference is in their add and delete functions
        chunk* traverse;
        traverse = top; //start
        while(traverse != NULL) {
            cout << traverse->value << endl;
            traverse = traverse->next;
        }
    }
};

int main() {
    Stack object;
    int choice, value;

    while(1) {
        cout << "Press 1 to add (push) to the stack" << endl;
        cout << "Press 2 to delete (pop) from the stack" << endl;
        cout << "Press 3 to display" << endl;
        cout << "Anything else to quit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Add what?" << endl;
                cin >> value;
                object.push(value);
                break;
            case 2:
                object.pop();
                break;
            case 3:
                object.display();
                break;
            default:
                exit(1);
        }
    }
    return 1;
}