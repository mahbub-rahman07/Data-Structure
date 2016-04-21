#include <iostream>
using namespace std;

void Selection(int arr[],int n)
{
	int i,j,temp,imin ;
	for(i=0;i<n-1;i++){
		imin = i;
		for(j=i+1;j<n;j++){
			if(arr[j] < arr[imin]){
				imin = j;
			}
			
		}
		
			temp = arr[i];
			arr[i] = arr[imin];
			arr[imin] = temp;
		
	}
	
	
}


int main() {
	
	int A[] = {8,2,5,1};
	int n = 4;
		
	Selection(A,n);
	
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	
	
	return 0;
}