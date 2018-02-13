#include<iostream>
using namespace std;

class Shoe {
    //everything inside a class definition has access to everything else in that class
    //only public attributes and functions can be accessed from outside of the class
    public:
        //1. attributes
        float price;
        float size;
        char color;

        //2. constructor is a special function that returns nothing, not even void
        Shoe() {
            price = 100.00;
            size = 6.5;
            color = 'b';
        }

        //3. functions
        void itemOnSale() {
            price = price / 2;
        }
};

int main() {
    //to prevent a pointer from randomly pointing at anything when created, you can assign it to
    //NULL or to an address with an ampersand '&'

    //a class is a template for a certain type of an object
    //instead of creating variables inside of the main function, it makes sense to make them in a class
    Shoe item1; //compiler will implicitly call the constructor

    //we use the DOT operator to access attributes and functions associated with a particular object
    cout << "Price of item 1: " << item1.price << endl;
    item1.price = 200.00;
    cout << "Price of item 1: " << item1.price << endl;
    return 1;
}