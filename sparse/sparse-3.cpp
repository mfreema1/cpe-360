#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Node {
    public:
        int val;
        int row;
        int col;
        Node* next;

        Node(int val, int row, int col) {
            this->val = val;
            this->row = row;
            this->col = col;
            next = NULL;
        }

        bool isSameRowCol(Node* node) {
            return this->row == node->row && this->col == node->col;
        }

        bool isGreaterRowCol(Node* node) {
            if(this->row < node->row)
                return false;
            else if(this->col <= node->col)
                return false;
            return true;
        }
};

class SparseMatrix {
    public:
        Node* head;
        
        SparseMatrix() {
            head = NULL;
        }

    void addNodeToEnd(Node* temp) {
        //keep in mind that temp is not the name of the object,
        //but rather the pointer that finds it for us
        if(head == NULL)
            head = temp;
        else {
            //the list isn't empty, traverse to the end of the list
            Node* trav = head;
            while(trav->next != NULL) {
                trav = trav->next;
            }
            //trav is now at the last element of the list
            //throw in our new element
            trav->next = temp;
        }
    }

    void populateMatrix() {
        for(int row = 0; row < 10; row++) {
            for(int col = 0; col < 10; col++) {
                if((rand() % 100 + 1) <= 5) { //insert a 1 5% of the time
                    //logic accounting for empty list built into func
                    this->addNodeToEnd(new Node(1, row + 1, col + 1));
                }
            }
        }
        cout << "Matrix generated" << endl;
    }

    void printMatrix() {
        Node* trav = this->head;
        for(int row = 0; row < 10; row++) {
            for(int col = 0; col < 10; col++) {
                if(trav != NULL && (trav->row == row + 1 && trav->col == col + 1)) {
                    cout << " " << trav->val << " ";
                    trav = trav->next;
                }
                else
                    cout << " 0 "; 
            }
            cout << endl;
        }
    }
};

SparseMatrix mergeMatrix(Node* headA, Node* headB) {
    static SparseMatrix mat_c = SparseMatrix();
    //generate a new matrix instead of modifying either
        if(headA == NULL) {
            //if headA is null, merge the rest of B into C
            while(headB != NULL) {
                mat_c.addNodeToEnd(new Node(headB->val, headB->row, headB->col));
                headB = headB->next;
            }
            return mat_c;
        }
        else if(headB == NULL) {
            //if headB is null, merge the rest of A into C
            while(headA != NULL) {
                mat_c.addNodeToEnd(new Node(headA->val, headA->row, headA->col));
                headA = headA->next;
            }
            return mat_c;
        }
        else {
            //otherwise we got work to do
            if(headA->isSameRowCol(headB)) {
                mat_c.addNodeToEnd(new Node(headA->val + headB->val, headA->row, headA->col));
                return mergeMatrix(headA->next, headB->next);
            }
            //if we get no match, let's start adding till we do, keep a max
            else if(headA->isGreaterRowCol(headB)) {
                while(headB != NULL && headA->isGreaterRowCol(headB)) {
                    mat_c.addNodeToEnd(new Node(headB->val, headB->row, headB->col));
                    headB = headB->next;
                }
                //headA is either equal or lesser now, let's recurse to see what changed
                mat_c.addNodeToEnd(new Node(headA->val, headA->row, headA->col));
                return mergeMatrix(headA->next, headB);
            }
            //same thing, except headB is the bigger one
            else {
                while(headA != NULL && headB->isGreaterRowCol(headA)) {
                    mat_c.addNodeToEnd(new Node(headA->val, headA->row, headA->col));
                    headA = headA->next;
                }
                //same as above, either less or equal now, let's recurse
                mat_c.addNodeToEnd(new Node(headB->val, headB->row, headB->col));
                return mergeMatrix(headA, headB->next);
            }
        }
    }

int main() {
    srand(time(NULL));
    SparseMatrix mat_a = SparseMatrix();
    SparseMatrix mat_b = SparseMatrix();
    SparseMatrix mat_c = SparseMatrix();
    mat_a.populateMatrix();
    mat_b.populateMatrix();
    mat_c = mergeMatrix(mat_a.head, mat_b.head);
    mat_a.printMatrix();
    cout << endl;
    mat_b.printMatrix();
    cout << endl;
    mat_c.printMatrix();
    return 1;
}