#include<iostream>
using namespace std;

//signature: what does it return? what is its name? what are the args?
void add(int x, int y) {
    int result;
    result = x + y;
    return result;
}

int main() 
{
    //story of a variable
    //variables have a lifecycle, they can both be born and die
    int var;
    var = 5;

    //curly braces denote a scope, and thus, the birth and death of all variables
    //associated with that scope

    cout << "Value of var: " << var << endl;
    cout << "The address of var: " << &var << endl;

    //The & symbol will literally give you the address of that variable in memory
    //The address will always start with 0x, which just means what follows is hexadecimal

    //once you have the address of a variable, you can do all sorts of freaky things with it

    //when you call a function, a block is assigned to it in memory.  After that function finishes, it will return
    //or release that memory back to the OS.  The compiler only really cares about main when it is initially called,
    //and doesn't immediately give memory to any other function

    //it's also worth noting that functions work with copies generally.  These x and y are different than the
    //x and y in the add function
    int x = 10;
    int y = 100;
    add(x, y);

    //when a function returns a value, you can think of the entire function as a variable of the type it returns
    cout << "Result: " << add(x, y) << endl;

    return 1;
}