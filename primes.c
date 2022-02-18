
#include<stdio.h>  
#define N 100  
  
int prime()  
{  
    int num[N], i, j;  
  
    for(i = 0; i < N; i++)  
        num[i] = i + 1;  
  
    for(i = 1; (num[i] * num[i]) <= N; i++)    //divisor <= square root (N)
    {  
        if(num[i] != 0)  
        {  
            for(j = num[i] * num[i]; j <= N; j += num[i])  
            {  
                num[j - 1] = 0;  
            }  
        }  
    }  
  
    printf("Sieve of Eratosthenes Method\n");  
    printf("To find Prime numbers from 2 to %d\n\n", N);  
    for(i = 1; i < N; i++)  
    {  
        if(num[i] != 0)  
            printf("%d\t", num[i]);  
    }  
  
    printf("\n");  
  
    return 0;  
}  


//PASCAL TRIANGLE using multi dimensional array
#include<stdio.h>
// function to print Pascal's Triangle
int PascalsTriangle(int n) {
    int arr[100][100];
    int i, j;
    for (i = 0; i < n; ++i) {
        // printing spaces
        for (j = 0; j < n - 1 - i; ++j) {
            printf(" ");
        }
        // calculating then printing the data of ith
        // row of Pascal's Trianle
        for (j = 0; j <= i; ++j) {
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter Number of Rows in Pascal's Trianle : ");
    scanf("%d", &n);
    PascalsTriangle(n);
    return 0;
}