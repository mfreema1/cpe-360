#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));

    //range of 1 --> 10
    int secret = rand()%10 + 1;
    int userGuess, count = 0; //allow three attempts to guess the number

    while(count < 3) {
        cout << "Guess " << count + 1 << endl;
        if(userGuess == secret) {
            cout << "You win, wow!!" << endl;
            exit(1);
        }
        count++;
    }
    cout << "Secret: " << secret << endl;
    return 1;
}