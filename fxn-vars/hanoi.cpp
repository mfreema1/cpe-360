#include<iostream>
using namespace std;

void hanoi(int N, char S, char I, char D) {
    //BASE case
    static int count = 0;
    if(N == 1)
        cout << "Move number: " << ++count << endl
        cout << "Move disk " << N << " from " << S << " -- > " << D << endl;
    else {
        //move to smaller instance of the problem
        hanoi(N - 1, S, D, I); //move N - 1 from S to I, using D
        cout << "Move disk " << N << " from " << S << " -- > " << D << endl;
        hanoi(N - 1, I, S, D); //move N - 1 from I to D, using S
    }
}

int main() {
    int N;
    char S = 'S', D = 'D', I = 'I';

    cout << "Give me the number of disks: " << endl;
    cin >> N;

    hanoi(N, S, I, D);
    return 1;
}