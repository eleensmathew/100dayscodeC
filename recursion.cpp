#include <iostream>
using namespace std;

// //Tower of Hanoi
// Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
// The objective of the puzzle is to move the entire stack to another rod, obeying the
// following simple rules:
// 1) Only one disk can be moved at a time.
// 2) Each move consists of taking the upper disk from one of the stacks and placing
// it on top of another stack i.e. a disk can only be moved if it is the uppermost disk
// on a stack.
// 3) No disk may be placed on top of a smaller disk.

//LOGIC move n-1 tiles from top to helper rod, then move the last tiles to destination rod, then move the n-1 tiles from helper rod to destination rod
void towerofhanoi(int n, char src, char dest, char helper){
    if (n==0){
        return;
    }
    towerofhanoi(n-1, src,helper,dest);
    cout<<"Move from "<<src<<"to "<<dest<<endl;
    towerofhanoi(n-1,helper,dest,src);
}
//remove duplicates   //space complexity n^2 time complexity n^2
string removeduplicates(string word){
    if (word.length()==0){
        return "";
    }
    char ch=word[0];
    string ans=removeduplicates(word.substr(1));
    if (ch==ans[0]){
        return(ans);
    }
    return(ch+ans);
}
//Print all the possible subsequences
//every possible substring will either 2 choices to inlude ine substring or not
//its like the process of pascal triangle
//time complexity 2^n space complexity 2^n
void possub(string s,string ans){
    if (s.length()==0)
    {cout<<ans<<endl;
    return;}
    char ch=s[0];
    string ros=s.substr(1);
    possub(ros,ans+ch);
    possub(ros,ans+"");


}

//move all character 'x' to th end of the string
//time complexity n^2
string movex(string s,char x)
{
    if (s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans=movex(s.substr(1),x);
    if (ch==x){
        return(ans+ch);
    }
    return(ch+ans);
}
//print permutations
void perm(string word,int n,int l){
    
    if (l==n){
        cout<<word<<endl;
    }
    else{
        
        for (int i = l; i < n; i++)
        {
            
            char ch=word[l];
            word[l]=word[i];
            word[i]=ch;
            
            perm(word,n,l+1);
            ch=word[l];
            word[l]=word[i];
            word[i]=ch;


        }
        
        
    }
}
//count the number of paths possible from starting point to ending point 
//LOGIC ex 0-> 4 using recursion count the paths from 0->3 one will be directly from 0->3 and other would be from 1+ paths form 1->3 and so on
int countpaths(int start,int end){
    
    if (start==end){
        return 1;
    }
    if(start>end){
        return 0;
    }
    int count=0;
    for (int i = 1; i <=6; i++)//steps can max be 6 units long because we are using a dice
    {
        count+=countpaths(start+i,end);
    }
    return count;
}
//count the number of paths in a 2d grid
int countpathmaze(int n, int i, int j){
    if(i==n-1 && j==n-1){return 1;}
    if(i>=n || j>=n){return 0;}
    return countpathmaze(n,i+1,j)+countpathmaze(n,i,j+1);
} 

//Tiling problem Given a 2xn board and tiles of size 2x1 count the number of ways to tile the board using the tiles in any order
int tiles(int n){
    if (n==0){
    return 0;
    }
    if (n==1){
    return 1;
    }
    return tiles(n-1)+tiles(n-2);//vertial+horizontal
}
// Find the number of ways in which n friends can remain single or can be paired up.
 int friendsPairing(int n){

    if(n==0 || n==1 || n==2){
        return n;
    }
    return friendsPairing(n-1)+friendsPairing(n-2)*(n-1); //single people so n-1 will be left +paired (she has options to pair with n-1) and n-2 will be left
 }
int main(){
    //towerofhanoi(3,'A','C','B');
    //cout<<removeduplicates("aabbbbb");
    //possub("asdfg","");
    

//string a;
//cin>>a;
//perm(a,a.length(),0);
cout<<countpathmaze(3,0,0)<<endl;
}

