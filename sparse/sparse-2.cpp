#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class SparseMatrix {
public:
	MatrixElement *head;
	SparseMatrix() {
		head = NULL;
	}
	//create these two functions by Tuesday
	void addElement(int row, int col, int value) {
		//add an element all the way to the end of the list
		//grab a temp = new MatrixElement, temp->row, temp->col, etc to value
		//grab another traverse, walk to the end
		//knit in 'temp' to the structure
	}

	void display() {

	}
};

class MatrixElement {
    public:
        int row;
        int col;
        int value;
        MatrixElement *next;

    MatrixElement() {
        row = 0;
        col = 0;
        value = 0;
        next = NULL;
    }
};

int main() {
    srand(time(NULL));
    int guess;
    MatrixElement *matA = NULL, *tempA = NULL;

    //let's say we generate a 10x10 matrix, such that only 5% of its elements are non-zero
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            guess = rand()%100 + 1;//guess is in the range 1 -- 100
            if(guess <= 5){
                //the guess falls in that probability region
                //we're going to create a new chunk in Matrix A
                //1. If matrixA is empty, get a new node and make it the first
                //2. If it's not empty, add to the end
                if(matA == NULL) {
                    matA = new MatrixElement;
                    matA->row = i + 1;
                    matA->col = j + 1;
                    matA->value = 1;
                    tempA = matA;
                }
                else {
                    //there's already smoething in the matrix
                    tempA->next = new MatrixElement;
                    tempA = tempA->next;
                    tempA->row = i + 1;
                    tempA->col = j + 1;
                    tempA->value = 1;
                }
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }         
        }
        cout << endl;
    }
    cout << "Just generated the matrix and stored it in the heap" << endl;
    //PART II: Use linked list to print the matrix on screen
    //we have matA, the pointer which stores the entire list.
    int done = 0; //done = 0 means we are not done with the linked list
    tempA = matA; //start tempA at the beginning of Matrix A

    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(done != 1) {
                //am I at the coordinates for printing non-zero
                if(tempA->row == i + 1 && tempA->col == j + 1) {
                    cout << " " << tempA->value << " ";
                    tempA = tempA->next;
                    if(tempA == NULL)
                        done = 1;
                }
                else {
                    cout << " " << 0 << " ";
                }
            }
            else {
                cout << " " << 0 << " ";
            }
        }
        cout << endl;
    }
    return 1;
}
