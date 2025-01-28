 #include<iostream>
using namespace std;
int main(){
    int matrix[3][3]={{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
    int n =sizeof(matrix)/sizeof(matrix[0]);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int temp = matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            int temp = matrix[i][j];
            matrix[i][j]=matrix[i][n-1-j];
            matrix[i][n-1-j]=temp;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}