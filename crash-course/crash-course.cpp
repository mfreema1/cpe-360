#include<iostream>
using namespace std;

//a function, just like a variable, must be declared before its use,
//otherwise it simply won't work
void add(int x, int y)
{
    //lvalue -- rvalue
    //you can only have 1 lvalue, but you can have as many rvalues as you want
    int result;
    result = x + y;
    cout << "Result: " << result << endl;
}

//RETURN? NAME? (ARGS1?, ARGS2?,...) :: SIGNATURE OF A FUNCTION
//Even with function overloading, every function must have a unique signature

//computer will always head straight to the main function
int main()
{
    //if you initialize a variable, it will start with whatever value
    //just happens to be sitting in that memory.  For that reason, you
    //should give it a value if you plan to use it immediately
    int val1, val2;

    cout << "Give me a number: " << endl;
    cin >> val1;

    cout << "Another number please: " << endl;
    cin >> val2;

    //a function just takes these values and dumps them into the
    //arguments of the function
    add(val1, val2);

    //a condition of an if statement must always evaluate to a true
    //or false answer
    if(val1 > 0)
        cout << "It's more than zero" << endl;
    else
        cout << "It's less than zero" << endl;
    
    //for loops just repeat a code block a given number of times
    for(int i = 0; i < 5; i++)
        cout << "Print this again and again" << endl;

    //while loops are used when we don't really know how many times we
    //want to do something, rather we just know a condition we want to
    //have control the loop
    while( val1 > 0) {
        cout << "Print this" << endl;
        cout << "Give me a new value for val1" << endl;
        cin >> val1;
    }

    //all programs are run on top of the OS. Returning 0 or 1 indicates
    //to the OS that the program executed successfully
    return 1;
}

/*
* Since Visual Studio Code does not have a built in compiler, we will be using
* g++ for this.  You will need to type g++ filename.cpp to compile, and then
* ./a.out to execute in terminal
*/