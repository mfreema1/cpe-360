#include<iostream>
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

class LL {
    public:
        chunk* head;
        int length;

        LL() {
            head = NULL;
            length = 0;
        }

    void insertAtHead(int x) {
    //samea s a queue or a stack
    //make sure you do length++ each time you add
    }
    //add: you should be able to add anywhere
    void addAnywhere(int x, int pos) {
        //first you'll want to compare pos with length + 1 to make sure that the position is valid
        if(pos <= length + 1) {
            //inserting at the head and right at the end are edge cases and must be handled differently
            if(pos == 1) {
                insertAtHead(x);
            }
            else if (pos == length + 1) {
                //grab a couple of pointers, one gets you a new chunk, the other gets you the chunk all the way at the end
                //knit this new chunk in
            }
            else {
                chunk* temp = new chunk();
                temp->value = x;
                chunk* traverse = head;
                //run to the chunk before the one we want to knit in
                for(int i = 1; i < pos; i++) {
                    traverse = traverse->next;
                }
                temp->next = traverse->next;
                traverse->next = temp;
            }
            length++;
        }
        else {
            cout << "Invalid position" << endl;
            return;
        }

    }
    //remove: you should be able to remove anywhere
    void removeAtPosition(int pos) {
        if(pos <= length) {
            if(pos == 1) {
                //same as a stack
            }
            else if(pos == length) {
                //same as a queue
            }
            else {
                chunk *temp, *target;
                temp = target = head;
                for(int i = 1; i <= pos; i++) {
                    temp = target;
                    target = target->next;
                    //target always is one step ahead of the temp
                }
                temp->next = target->next;
                delete target;
            }
            length--;
        }
    }

    void searchAndDelete(int x) {
        //if you find it, you delete it, if you don't, you don't delete it
        //you need to look for the thing and then remove it
        chunk *fast, *slow;
        fast = slow = head;
        while(fast != NULL) {
            slow = fast;
            if(fast->value == x) {
                //you found it
                //delete it
                //update length
                //break out of the loop
            }
        }
        if(fast == NULL) {
            //could not find it, couldn't delete
            //return from function
        }
    }
    //also be sure to do length-- each time you remove
    //display:
};

int main() {
     return 1;
}