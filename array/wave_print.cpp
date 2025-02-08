#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(int nums[][6], int nrows, int ncols) {
    vector<int> ans;

    for (int col = 0; col < ncols; col++) {
        if (col & 1) { // Odd column: bottom to top
            for (int row = nrows - 1; row >= 0; row--) {
                ans.push_back(nums[row][col]);
            }
        } else { // Even column: top to bottom
            for (int row = 0; row < nrows; row++) {
                ans.push_back(nums[row][col]);
            }
        }
    }

    return ans;
}

int main() {
    int nums[4][6];

    // Taking input
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> nums[i][j];
        }
    }

    // Calling wavePrint function
    vector<int> result = wavePrint(nums, 4, 6);

    // Printing result
    cout << "Wave Print Output: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
