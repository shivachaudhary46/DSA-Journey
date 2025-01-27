#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fibo(int data){
    if(data == 0){
        return 0;
    }else if(data == 1){
        return 1;
    }else{
        return fibo(data-1) + fibo(data - 2);
    }
}

void fibonacci(){
    int n;
    int j;

    printf("write a program to find fibonaccii by using recursion ;  \n ");
    printf("enter the number; ");
    scanf("%d", &n);
    printf(" \n");

    printf("fibonaaci upto %d \n", n);
    printf("\n");

    for(int i=0; i<n; i++){
        j = fibo(i);
        printf("%d ", j);
    }
    printf("\n");

}

int fact(int data){
    if(data == 0){
        return 1;

    }else{
        return data * fact(data-1);
    }
}

void factorial(){
    int n;

    printf("write a program to find factorial by using recursion ;  \n \n \n");
    printf("enter the number; ");
    scanf("%d", &n);
    printf(" \n \n");

    printf("factorial of %d is %d  \n", n, fact(n));

    printf("\n");
}
void Hanoi(int n, int *moveCount, char src, char btwn, char dest){
    //base case 
    if(n==1){
        (*moveCount)++;
        printf("move no: %d, moved disk from %c to %c \n", *moveCount, src, dest);
        return;
    }

    //recursive calls 
    Hanoi(n-1, moveCount, src, dest, btwn);
    (*moveCount)++;

    //processing
    printf("move no: %d, moved disk from %c to %c \n", *moveCount, src, dest);

    //recursive calls 
    Hanoi(n-1, moveCount, btwn, src, dest);
}


void towerOfHanoi(){
    int n;
    int ans;
    int ptr = 0;

    printf("Enter number of disks: ");
    scanf("%d", &n);
    ans = pow(2, n)-1;
    printf("Tower of Hanoi with %d disks:\n", n);
    Hanoi(n, &ptr, 'A', 'B', 'C');  
    printf("minimum steps taken to move %d disk from src to dest = %d \n", n, ans);
}

int hcf(int n1, int n2) {
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
        return n1;
}

void gcd_algo(){
    int a, b;

    printf("write a program to find gcd by using recursion ;  \n ");
    printf("enter the number a; ");
    scanf("%d", &a);
    printf("enter the number b; ");
    scanf("%d", &b);
    printf(" \n");

    printf("gcd of (%d, %d) is %d  \n", a, b, hcf(a, b));
}


int main(){

    int n;

    do{
        printf("enter the number for \n 1.fibonacci \n 2.gcd \n 3.factorial \n 4.tower of hanoi \n 5.exit :");
        scanf("%d", &n);

        if(n == 5){
            break;
        }

        switch(n){
            case 1:
                fibonacci();
                break;
                
                
            case 2:
                gcd_algo();
                break;

            case 3:
                factorial();
                break;
            
            case 4:
                towerOfHanoi();
                break;

            default:
                printf("invalid input \n");
                exit(0);
        }
    }while(n != 5);
}