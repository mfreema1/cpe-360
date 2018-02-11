#include<iostream>
using namespace std;

//global variable
int var;

int main() {
    //the asterisk in front of this changes everything
    //you're creating a variable that can only store addresses of other
    //variables.  This is known as a pointer.

    //to declare a pointer you must use *
    //you must also give it a type, because the address only tells the address of the first bit or
    //least significant bit (in this architecture), and it must know the bounds of what it can modify,
    //which depends on the type

    //just like you might give a friend the key to your house so they can go inside,
    //the friend of x has the address of x, so it can go inside

    //regular variables don't really come to meet each other and are not really aware of each other

    int *friend_of_x;
    int x = 10;
    int y = 20;

    //assigning an address to the pointer, you don't use a *, this is called referencing the pointer
    friend_of_x = &x; //friend of x becomes aware of the address of x

    //if you have the address of the variable, you can act as if you were the variable
    //just like if someone has the keys to your house, they can go in and move your furniture,
    //eat your food, and basically pretend they live there

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x <<endl;

    //we'll get friend of x to change the value of x from 10 to 30
    //the asterisk denotes that you are acting as that variable, which is why we can assign 30 to it
    //this is dereferencing the pointer
    *friend_of_x = 30;

    cout << "Value of x: " << x << endl;

    friend_of_x = &y;//assigning the pointer to y's address now, it will lose access to x and
    //forget about it completely

    //a static variable is a variable that is only created one time.  Each call to a function then
    //does not recreate that variable, but instead keep the value of the variable
    return 1;
}