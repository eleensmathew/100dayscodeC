#include <iostream>
using namespace std;

void merge(int arr[], int l, int r, int mid){
int size1=
}
void mergeSort(int arr[],int l,int r){
if (l<r){
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(mid+1,r);
    merge(arr,l,r,mid);

}
}