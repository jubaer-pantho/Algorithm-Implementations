//bellman-ford
#include<stdio.h>
#include<malloc.h>

int arr[8][8];

int initialized[8];

int main()
{	
	arr[0][1] = 10;
	arr[0][7] = 8;
	arr[7][6] = 1;
	arr[6][5] = 1;
	arr[6][1] = -4;
	arr[1][5] = 2;
	arr[4][5] = -1;
	arr[3][4] = 3;
	arr[2][3] = 1;
	arr[5][2] = -2;
	
	int *dist;
	
	dist = (int *) malloc(8*sizeof(int));
	dist[0]=0;
	initialized[0] = 1;

	for(int i=1;i<8;i++)	dist[i] = 2000;
	
	for(int i=1;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(initialized[j])
			{
				for(int k=1;k<8;k++)
				{
					if(arr[j][k])
					{
						int temp = dist[j] + arr[j][k];
						if(temp < dist[k])
						{
							dist[k] =temp;
							initialized[k] = 1;						
						}
					}
				}
			}
		}
	}
	for(int i=0;i<7;i++)
	{
		printf("distance %c =%d\n", i+'A' ,dist[i+1]);
	}	
	
return 0;
}
