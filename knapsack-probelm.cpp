//knapsack algorithm
//author: Md Jubaer Hossain Pantho

#include<stdio.h>
#include<iostream>

using namespace std;


int main(int argc , char* argv[])
{
	int items = 4;
	int bagWeights = 5;
	
	int itemWeights[items] = {2,3,4,5};
	int itemValue[items] = {3,7,2,9};
	
	int mat[items+1][bagWeights+1];
	
	for(int i=0;i<=items;i++)
	{
		mat[i][0] = 0;
	}
	
	for(int i=0;i<=bagWeights;i++)
	{
		mat[0][i] = 0;
	}
	
	for(int i=1;i<=items;i++)
	{
		for(int j=1;j<=bagWeights;j++)
		{
			if(itemWeights[i-1]<=j)
			{
				int tempValue = itemValue[i-1];				
				int tempRemain = j - itemWeights[i-1];
				
				tempValue += mat[i-1][tempRemain]; 
				
				if(tempValue>mat[i-1][j])
				{
					mat[i][j] = tempValue;
				}
				else
				{
					mat[i][j] = mat[i-1][j];
				}
			}
			else
			{
				if(mat[i][j-1]>mat[i-1][j])
					mat[i][j] = mat[i][j-1];
				else
					mat[i][j] = mat[i-1][j];	
			}
			
		}
		
	}

printf("maximum profit %d\n", mat[items][bagWeights]);


return 0;
}

