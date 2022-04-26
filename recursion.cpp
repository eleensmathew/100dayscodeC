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
int main(){
    //towerofhanoi(3,'A','C','B');
    //cout<<removeduplicates("aabbbbb");
    //possub("asdfg","");
    cout<<movex("vhxxxdcxxxxfdx",'x');
}

