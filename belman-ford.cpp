//bellman-ford
#include<stdio.h>
#include<malloc.h>

#define MAX 200
#define INFINITY 5000

int initialized[MAX];

int main()
{	
	int N;
	
	printf("Enter the number of nodes: ");
	scanf("%d", &N);
	int arr[N][N];
	
	for(int i=0;i< N;i++)
		for(int j=0;j<N;j++)
			arr[i][j] = 0;
/*	
 * sample data
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
*/	
	
	int edges;
	printf("Enter Number of edges: ");
	scanf("%d", &edges);
	printf("Enter origin destination and cost:\n");
	
	for(int i=0;i< edges;i++)
	{
		int origin, destination, value;
		printf("edge %d : ",i);
		scanf("%d%d%d", &origin, &destination, &value);
		
		arr[origin][destination] = value;
	}	

	int *dist;	
	dist = (int *) malloc(N*sizeof(int));
	
	dist[0]=0;   // 0 index is the source 
	initialized[0] = 1;

	for(int i=1;i<N;i++)	
		dist[i] = INFINITY;
	
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(initialized[j])
			{
				for(int k=1;k<N;k++)
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
	
	printf("resulting distance:\n");
	for(int i=0;i<(N-1);i++)
	{
		printf("distance %c =%d\n", i+'A' ,dist[i+1]);
	}	
	
return 0;
}
