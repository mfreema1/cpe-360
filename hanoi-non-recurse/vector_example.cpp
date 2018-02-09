#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> column;
    column.push_back(1);
    column.push_back(2);
    column.push_back(3);
    column.push_back(4);

    for(int i = 0; i < 4; i++) {
        cout << column[i] << endl;
    }

    cout << "Size of vector: " << column.size() << endl;
}