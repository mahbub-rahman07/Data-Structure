#include<iostream>
#include<math.h>
#include<cstdlib>
#include<conio.h>
using namespace std;
void Swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void Bublesort(int *a,int n)
{
    for(int i=1;i<n;i++){
        for(int j=n-1;j>=i;j--){
            if(a[j-1]>a[j]){
                Swap(a[j-1],a[j]);
            }
        }
    }
}
/// Recursive BinerySearch
int ReBinery(int a[],int start,int end,int Tofind)
{
    int mid;
    if(start<=end){
        mid = (start+end)/2;

        if(a[mid]==Tofind) return mid+1;
        else if(a[mid]>Tofind) return ReBinery(a,start,mid-1,Tofind);
        else{
            return ReBinery(a,mid+1,end,Tofind);
        }

    }
    return 0;

}



int BinerySearch(int a[],int len,int Tofind)
{
    int start,end,mid;
    start = 0;
    end = len-1;
    while(start!=end){

        mid = (start+end)/2;

        if(a[mid]==Tofind)return mid+1;

        else if(a[mid]>Tofind)
            end = mid-1;

        else
            start = mid+1;
    }
    return 0;
}

int main()
{
    int arr[100],n,x;
    cout<<"How many data u want to store : ";;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    Bublesort(arr,n);
    cout<<"What u want to find : ";
    cin>>x;

  //  int found = BinerySearch(arr,n,x);
    int found = ReBinery(arr,0,n,x);
    if(found)
        cout<<"found at "<<found<<endl;
    else
        cout<<"Not Found"<<endl;


    return 0;
}
