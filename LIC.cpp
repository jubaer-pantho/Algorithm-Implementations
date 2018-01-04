#include<stdio.h>
#include<iostream>

using namespace std;

int maxL[6];	
int L[6];

int main(int argc, char *argv[])
{
	
	int a[] = {3,2,5,4,6,1};
	
	int size = sizeof(a)/sizeof(int);

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
	
//	cout << maxL[5];
	
	for(int i=0;i<6;i++)
	cout << maxL[i]<< " ";

return 0;	
}
