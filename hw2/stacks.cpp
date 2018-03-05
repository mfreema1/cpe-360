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

class stack {
    chunk* top;
    public:
        stack() {
            top = NULL;
        }
    void push(int x) {
        chunk* temp = new chunk;
        temp->value = x;
        if(top == NULL) {
            top = temp;
        }
        else{
            temp->next = top;
            top = temp;
        }
    }
    void pop() {
        if(top == NULL) {
            cout << "Your stack is empty" << endl;
            return;
        }
        else {
            chunk* temp;
            temp = top;
            top = top->next;
            delete temp;
        }
    }
    void displayContents() {
        chunk* traverse;
        traverse = top;
        while(traverse != NULL) {
            cout << traverse->value << endl;
            traverse = traverse->next;
        }
    }
};

int main() {
    stack object;
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
                object.displayContents();
                break;
            default:
                exit(1);
        }
    }
    return 1;
}