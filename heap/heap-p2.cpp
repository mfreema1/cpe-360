#include<iostream>
using namespace std;

class Shoe {
    public:
        float price;
        float size;
        char color;

        Shoe() {
            price = 100.00;
            size = 6.5;
            color = 'b';
        }

        void itemOnSale() {
            price = price / 2;
        }
};

int main() {
   
    Shoe item1;
    int x;

    x = 10;

    //address of item x
    cout << "Address of item: " << &item1 << endl;
    cout << "Address of x: " << &x << endl;

    int* ptr; //integer pointer
    Shoe* shoeptr; //Shoe pointer

    //get our pointers to point to the boxes
    ptr = &x;
    shoeptr = &item1;

    //let's get these pointers to go change the variable values
    //this is called accessing a value beyond the pointer
    //equivalent to *shoeptr.price = 500.00
    shoeptr->price = 500.00;
    shoeptr->size = 10.5;

    return 1;
}