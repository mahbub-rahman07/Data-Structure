#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int Partition(int *A,int start,int end)
{
   // cout<<start<<" "<<end<<endl;
    int pivot = A[end];
    int pertitionIndex=start;
    for(int i=start;i<end;i++){
        if(A[i]<=pivot){
            swap(A[i],A[pertitionIndex]);
            pertitionIndex++;
        }
    }
    swap(A[end],A[pertitionIndex]);
    return pertitionIndex;
}



void quick(int *A,int start,int end)
{
    int pertitionIndex;
    if(start<end){
        pertitionIndex = Partition(A,start,end);
        quick(A,start,pertitionIndex-1);
        quick(A,pertitionIndex+1,end);

    }
}



int main()
{
    int A[] = {9,2,1,5,3,8,6,4};

    quick(A,0,7);

    for(int i=0;i<=7;i++)cout<<A[i]<<" ";


    return 0;
}

