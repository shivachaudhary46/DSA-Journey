 #include<iostream>
using namespace std;
vector<int> spiralPrint(int matrix[][5]){
    vector<int> ans;
    int row = 4;
    int col = 5;

    int startingRow=0;
    int startingCol=0;
    int endingRow=row-1;
    int endingCol=col-1;

    int count=0;
    int total=row*col;
    while(count<total){

        //print starting row
        for(int index=startingCol; count<total && index<=endingCol; index++ ){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        //printing ending col
        for(int index=startingRow; count<total && index<=endingRow; index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        //printing ending row 
        for(int index=startingCol; count<total && index<=endingCol; index++){
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        //printing starting col
        for(int index=startingRow; count<total && index<=endingRow; index++){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}
int main(){
    int matrix[4][5]={{3, 4, 5, 6, 7}, {11, 2, 3, 5, 6}, {4, 5, 6, 7, 8}, {3, 4, 5, 6, 7}};
    vector<int> ans=spiralPrint(matrix);

    for(int i=0; i<ans.size(); i++){
        cout<<ans.at(i)<<" ";
    }

}