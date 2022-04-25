//write a program to check if a given nuber is power of 2
//LOGIC when a number of power 2 'n' is & with 'n-1' 0 will be returned
#include <iostream>
using namespace std;

bool ispowerof2 (int n){
return (n && !(n&n-1));
}
//write a program to count the number of 1s in a binary interpretation of a number
//LOGIC we count the times when 'n' is & with 'n-1' until we get 0

int numberofones(int n){
    int count=0;
    while (n){
        n=n&(n-1);
        count++;
    }
    return count;
}
//write  a program to generate all possible subsets of a set
// Write a program to generate all possible subsets of a set
//        ex  {a, b, c}
//     
//         {}       000
//         {c}      001
//         {b}      010
//         {b,c}    011
//         {a}      100
//         {a,c}    101
//         {a,b}    110
//       {a,b,c}    111

// Algorithm:

// Run a loop for 'i' for all numbers from 0 to 2^(n-1).
// When inside this loop, run a loop for 'j' from 0 to n-1 inclusive
// Inside this loop, check if the 'j'th bit is SET(equal to 1) for the number 'i'.
// If it is, then we include this element in our 'i'th subset
// Done.
// I was very confused when I learnt this the first time, so let me demonstrate with a small example: say for i=3, the binary representation is 011. When we run the inner loop from 1 to n for i which is currently 3, here's what we are actially doing.

// Is the right most (LSB) bit set? Yes. So Include it. [01x]
// Is the middle bit set? Yes. So Include it. [0x1]
// Is the last (MSB) bit set? No. So Leave it out. [x11]
void findallsubsets(int arr[],int n){
    for(int i=0;i<(1<<n);i++)//loop takes place 2^n times
    {
        for (int j=0;j<n;j++){
            if (i &(1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}
// Write a program to find a unique number in an array where all numbers except one,are present twice
//LOGIC: using XOR
int findunique(int n,int arr[]){
    int xorsum=0;
    for (int i = 0; i < n; i++)
    {
        /* code */
        xorsum=xorsum^arr[i];
    }
    return xorsum;
}
//write a program to find 2 unique number in an array where all numbers except 2,are present twice
//LOGIC ex {2,6,4,7,4,5,6,2} when we xor all the elements we get 5^7 (0111^0101) we get 0010. There will be at least one bit set in x. Using that set bit, divide the original
// set of numbers into two sets
// a. First set which contains all the elements with that bit set.
// b. Second set which contains all the elements with that bit unset.
// 3. Take xor of both the sets individually, and let those xor values be x1 and x2.
// 4. Voila, x1 and x2 are our unique numbers. Reason: both the above sets
// contain one of the unique elements and rest elements of the sets occur
// twice which will get nullified after ⊕ operation.
int setBit(int n, int pos){
    return ((n&(1<<pos))!=0);
}
void find2unique(int n, int arr[]){
    int xorsum=0;
    for (int i = 0; i < n; i++)
    {
        xorsum=xorsum^arr[i];
        /* code */}
    int tempxor=xorsum;
    int setbit=0;
    int pos=0;//find the position of 1
    while(setbit!=1){
        setbit=xorsum &1; //checks if last digit is 1 otherwise returns 0
        pos++;
        xorsum=xorsum>>1;//removes the last digit
    }
    
    int newxor=0;
    for (int i = 0; i < n; i++)
    {
        if(setBit (arr[i],pos-1)){
            newxor=newxor^arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}
//  Write a program to find a unique number in an array where all numbers except one, are present thrice
// {1,3,2,3,4,2,1,1,3,2} we input an array of size 64 which will store the number of times ith bit has occurred in the array.
//{001,110,010,110,100,010,001,001,110,010}
//then we put a loop to see how many 1s are there in 1st position , how many 1s are there in 2nd position etc 
//[3,6,4,0,0,0...]
//2. Take the modulo of each element of this array with 3. Resultant array will represent the binary representation of the unique number.
// 3. Convert that binary number to decimal number and output it.
bool getBit(int n, int pos) {
    return ((n & (1 << pos)) != 0);
}
int setBit( int n, int pos) {
    return (n | (1 << pos));
}
int uniquein3(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < 64; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (getBit(arr[j], i)) { //find sthe number of 1s at position i
                sum++;
            }
        }
        if (sum % 3 != 0) {
            result = setBit(result, i);
        }
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    //cout<<ispowerof2(n);
    //cout<<numberofones(n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
 
    //findallsubsets(arr,n);
    find2unique(n,arr);
    cout<<uniquein3(arr,n)<<endl;
}
