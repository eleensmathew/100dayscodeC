// WAP to input a 2D array of size NxM (input N and M from user) and then print the sum of the border elements of the array. eg, if the array is:

// 1 2 3
// 4 5 6
// 7 8 9
#include <stdio.h>
int addborder(int n, int m,int arr1[n][m]){
    int sum=0;
    if(n==1 & m==1){
        sum=arr1[0][0];
    }
    else{
        sum=0;
        
        
        for (int k=0;k<m;k++){
            sum+=arr1[0][k];
            if (n>1){
                sum+=arr1[n-1][k];
            }
        }

        

        for (int k=1;k<n-1;k++){
            sum+=arr1[k][0];
            if (m>1){
                sum+=arr1[k][m-1];
            }
        }
        
    }    
    printf("%d",sum);
}
//WAP to accept a 2D array of size NxM (input N and M from user) and then print the sum of the elements of the array present at the main diagonal (from top left to bottom right).

int sumdiagonal(int n ,int m, int arr2[n][m]){
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum+=arr2[i][i];
    }   
    printf("%d",sum);
}

//WAP to accept a 2D array of size NxM (input N and M from user) and another 2D-array of size MxT (input T from user) and then print the matrix multiplication of the two matrices.
int matrix(int n ,int m,int arr[n][m]){
    
    int t;
    printf("Enter no of coloumns of 2nd array :");
    scanf("%d",&t);
    int arr2[m][t];
    for (int i=0;i<m;i++){
        for (int j=0;j<t;j++){
            printf("Enter value at index [%d][%d]: ",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    int product=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++ ){
            //printf("%d%d ",i,j);
            product+=arrelement(j,arr[i][j],t,arr2);
            
        }

    }
    printf("matrix sum is: %d",product);
    
}
int arrelement(int m, int p1,int t,int arr2[m][t]){
         int product=0;
         for (int y=0;y<t;y++){
              product=product+(arr2[m][y]*p1);
              //printf("%d*%d ",arr2[m][y],p1);
     }
     //printf("\n ");
     return product;
    }

int main(){
    int n,m;
    printf("Enter no of rows and coloumns");
    scanf("%d %d",&n,&m);
    int arr[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Enter value at index [%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    //addborder(n,m,arr);
    //sumdiagonal(n ,m, arr);
    matrix(n ,m, arr);

}

