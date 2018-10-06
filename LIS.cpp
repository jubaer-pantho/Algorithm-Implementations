//longest increasing subsequence

#include<stdio.h>
#include<iostream>

using namespace std;
#define LEN 6 

int maxL[LEN];	
int L[LEN];

int main(int argc, char *argv[])
{
	//sample string
	int a[] = {3,2,5,4,6,1};
	int size = sizeof(a)/sizeof(int);
	printf("string length : %d  \n", size);
	L[0]= maxL[0] = 1;
	
	for(int i=1; i< size;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[j] < a[i] && maxL[j] == L[j])
			{
				L[i] = L[j]+1;
				maxL[i] = maxL[i-1]>L[i]? maxL[i-1]:L[i];
				break;
			}			
			if(j==0)
			{
				maxL[i] = maxL[i-1];
				L[i] = 1; 
			}
		}
	}
	
	cout <<"LIC : "<< maxL[size-1] << endl;
	cout << "max L array: ";	
	for(int i=0;i<size;i++)
		cout << maxL[i]<< " ";

cout << endl;

return 0;	
}
