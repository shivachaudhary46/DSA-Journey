#include<iostream>
using namespace std;

int main(){
    int n, row, col, start, space;
    cout << "Enter the number n: ";
    cin >> n;

    for(row = 1; row <= n; row++) {
        // Printing spaces before the numbers in each row
        space = n - row;
        while(space) {
            cout << " ";
            space = space - 1;
        }

        // Printing the increasing part of the row
        start = row;
        for(col = 1; col <= row; col++) {
            cout << start;
            start = start + 1;
        }

        // Printing the decreasing part of the row
        start = start - 2;  // To reverse the increasing pattern
        for(col = 1; col < row; col++) {
            cout << start;
            start = start - 1;
        }

        cout << endl;
    }

    return 0;
}
