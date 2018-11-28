//merge sort
#include<stdio.h>
#include<iostream>
#include<string.h>


using namespace std;


void merge(int arr[], int l, int m, int r)
{
	int n1 = m-l+1;
	int n2 = r - m;
	int L[n1];
	int R[n2];
	int i,j,k;
	
	for(i=0;i<n1;i++)
		L[i] = arr[l+i];
	
	for(j=0;j<n2;j++)
		R[j] = arr[m+1+j];
	
	i=0;j=0;k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	
	while(i<n1)
		arr[k++] = L[i++];
	
	while(j<n2)
		arr[k++] = R[j++];
} 

void mergesort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m = (r+l)/2;	
		mergesort(arr, l , m);
		mergesort(arr, m+1, r);
		
		merge(arr, l, m, r);		
	}
}

int main(){
	
	int arr[] = {87,0,1,5,7,6,3,9,11};
	int arrLen = sizeof(arr)/sizeof(int);
	
	mergesort(arr, 0, arrLen-1);
	printf("\nsorted array: \n");
	for(int i=0;i<arrLen; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
