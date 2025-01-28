#include<iostream>
using namespace std;
//search in 2d array ||
#include<vector>
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowIndex=0;
        int colIndex=col-1;
        while(rowIndex<=row && colIndex>=0){
            int element=matrix[rowIndex][colIndex];

            if(element == target){
                return true;
            }else if(element < target){
                rowIndex++;
            }else{
                colIndex--;
            }
        }
        return false;
    }
int main(){
    vector<vector<int>> matrix={{3, 4, 5}, {4, 6, 7}};
    if(searchMatrix(matrix, 6))
}