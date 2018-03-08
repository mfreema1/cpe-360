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
        chunk* temp = new chunk;
        temp->value = x;
        if(length == 0) {
            head = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
        length++;
    }
    void insertAtPosition(int position, int x) {
        if(position >= 1 && position <= length + 1) { //check legitimacy of position
            if(position == 1)
                insertAtHead(x); //call already-defined func
            else {
                chunk* traverse;
                chunk* target = new chunk;
                target->value = x; //good-to-go, proceed w/ placement

                traverse = head; //put it at the front
                for(int i = 1; i < position - 1; i++) { //line up position
                    traverse = traverse->next;
                }
                target->next = traverse->next;
                traverse->next = target;
                length++;
            }
        }
        else
            cout << "Sorry that's an invalid position" << endl;
    }
    void removeFromPosition(int position) { //I want to clean this up, it's functional but not pretty
        if(position >= 1 && position <= length) { //check legitimacy for removal
            if(position == 1) { //remove head
                chunk* target;
                head = head->next;
                delete target;
                length--;
            }
            else if(position == length) { //remove tail
                chunk* traverse;
                traverse = head;
                while(traverse->next != tail) { //grab the second to last chunk
                    traverse = traverse->next;
                }
                traverse->next = NULL;
                delete tail;
                tail = traverse; //reassign the tail
                length--;
            }
            else { //remove in middle
                chunk *target, *traverse;
                target = traverse = head;
                for(int i = 1; i < position; i++) { //move target to chunk to delete, while traverse lags
                    traverse = target;
                    target = target->next;
                }
                traverse->next = target->next;
                delete target;
                length--;
            }
        }
        else
            cout << "Sorry that's an invalid position" << endl;
    }
    void displayContents() {
        chunk* traverse;
        traverse = head;
        while(traverse != NULL) {
            cout << traverse->value << endl;
            traverse = traverse->next;
        }
    }
    void deleteFirstInstance(int x) {
        int pos = 1;
        chunk* traverse;
        traverse = head;
        while(traverse != NULL) {
            if(traverse->value == x){
                removeFromPosition(pos);
                return;
            }
            traverse = traverse->next;
            pos++;
        }
        cout << "Sorry, that item wasn't in the list" << endl; //we would have returned otherwise
        //search the linked list for the value and delete it
    }
    void deleteAllInstances(int x) {
        int pos = 1;
        chunk* traverse;
        traverse = head;
        while(traverse != NULL) {
            if(traverse->value == x)
                removeFromPosition(pos);
            else
                pos++; //if you remove, positions will all shift down one, so dont increment
            traverse = traverse->next;
        }
    }
    //hunt a value and ask as you move through if you'd like to delete at that position
    // void sequentialSearchAndDelete() {

    // }
};

int main() {
    linkedList object;
    int choice, value, position;

    while(1) {
        cout << "Press 1 to insert at the head of the linked list" << endl;
        cout << "Press 2 to insert at a position" << endl;
        cout << "Press 3 to delete at a position" << endl;
        cout << "Press 4 to delete first instance of value" << endl;
        cout << "Press 5 to delete all instances of value" << endl;
        cout << "Press 6 to display" << endl;
        cout << "Anything else to quit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Add what?" << endl;
                cin >> value;
                object.insertAtHead(value);
                break;
            case 2:
                cout << "Where to add?" << endl;
                cin >> position;
                cout << "What to add?" << endl;
                cin >> value;
                object.insertAtPosition(position, value);
                break;
            case 3:
                cout << "Delete where?" << endl;
                cin >> position;
                object.removeFromPosition(position);
                break;
            case 4:
                cout << "Delete first instance of what value?" << endl;
                cin >> value;
                object.deleteFirstInstance(value);
                break;
            case 5:
                cout << "Delete all instances of what value?" << endl;
                cin >> value;
                object.deleteAllInstances(value);
                break;
            case 6:
                object.displayContents();
                break;
            default:
                exit(1);
        }
    }
    return 1;
}
