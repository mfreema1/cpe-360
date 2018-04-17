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

    MatrixElement *A = NULL;

    //let's say we generate a 10x10 matrix, such that only 5% of its elements are non-zero
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            guess = rand()%100 + 1;//guess is in the range 1 -- 100
            if(guess <= 5)
                cout << 1 << endl;
            else   
                cout << 0 << endl;
        }
        cout << endl;
    }
    return 1;
}