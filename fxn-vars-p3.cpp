#include<iostream>
using namespace std;


//this is the idea of recursion -- a function calling itself
int fact(int N) {
    if(N == 0 || N == 1)
        return 1;
    else
        return N * factorial(N - 1);
}

/*
* With recursion, you've got to be very clear about the BASE case, EXIT value, or ANCHOR value.
* if: simplest instance of the problem, with simplest solution to that problem.
* else: make a recursive step, and drive the original problem towards the base case.
*/

int main() {
    int N;
    cout << "Give me a number, I'll give you its factorial: " << endl;
    cin >> N;
    cout << fact(N) << endl;

    return 1;
}