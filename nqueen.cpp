//N Queen
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int** arr,int x, int y,int n){
    for (int row = 0; row < x; row++)  //checks coulumn
    {
        if (arr[row][y]==1)
        {return false;}
    }
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1)
        {return false;}//checks for diagonal '\'
        row--;
        col++;
    }
    
    
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){return false;} //checks for diagonal '/'
        row--;
        col--;
    }
    //we dont check row since we are not puuuting any 2 queens in the same row
    
    return true;
}

bool nQueen(int** arr, int x, int n){  //x is row number
    if (x>=n){
        return true;
    }
    for (int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            if( nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col]=0;
        }
    }
    return false;
}
//Kight tour
int isSafe(int x, int y, int** arr,int n){
    return(x>=0 && x<n && y>=0 && y<n && arr[x][y]==-1);
}

void printboard(int** arr,int n){
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout << " " << setw(2) << arr[i][j] << " ";
        
        }
        cout<<endl;
    }


}
int solve(int n,int x,int y,int movei,int** arr,int xmove[8],int ymove[8]){
    if (movei==n*n){
        return 1;
    }
    int k,next_x,next_y;
    //trying all moves
    for (k = 0; k < 8; k++)
    {
        /* code */
        next_x=xmove[k]+x;
        next_y=ymove[k]+y;
        if(isSafe(next_x,next_y,arr,n)){ 
            arr[next_x][next_y]=movei;
            if (solve(n,next_x,next_y,movei+1,arr,xmove,ymove)==1)
            {
                return 1;
            }
            else{ //backtaracking
                arr[next_x][next_y]=-1;
            }
        }
        
    }
    return 0;
}
int presolve(int n){
    int** arr=  new int*[n];
    for (int i = 0; i < n; i++) //initialising the board
    {
        arr[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]=-1;
        }
        
    }
    int xmove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int ymove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
    
    arr[0][0]=0;
    if (solve(n,0,0,1,arr,xmove,ymove)==0){
        cout<<"solution does not exist";
        return 0;
    } 
    else{
        printboard(arr,n);
    }  
    return 1;
}

int main(){
    int n;
    cin>>n;

    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]=0;
        }
        
    }
    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            
            for (int j = 0; j < n; j++)
            {
                cout<<arr[i][j]<<" ";
                
            }
            cout<<endl;
        }    
    }

    presolve(n);
    return 0;

}