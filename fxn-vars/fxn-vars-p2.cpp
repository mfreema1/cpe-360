#include<iostream>
using namespace std;

//function to calculate factorial
int fact(int N) {
    //N gets created ever time you call this function
    if(N == 0 || N == 1)
        return 1;
    else {
        int fact = 1;
        //fact also only gets created in this else block
        for(int i = 1; i <= N; i ++)
            fact *= i; //fact = fact * i;
        
        return fact;
    }
}
//this is a greedy way of solving the problem, meaning we're just brute-forcing it head on

int main()
{
    int var;

    cout << "So let's see what's inside var, we just created it: " << var << endl;

    int N;
    cout << "Give me a number, I'll give you its factorial: " << endl;
    cin >> N;
    cout << fact(N) << endl;
    
    return 1;
}