//Dijkstra's Algorithm
#include<stdio.h>
#include<iostream>

#define INFINITY 9999
#define MAX 100 
using namespace std;

int adjMat[MAX][MAX];

 
int myQueue[200];
int N=6;
int maxVertices;
int front = -1;
int rear = -1;

int visited[MAX];
int cost[MAX];

void qpush(int q)
{
	rear++;
	myQueue[rear] = q;	
}

int qpop()
{
	if(rear == -1)
	{
		printf("que is empty\n");
		rear  = -1;		
		return -6;
	}
	else
	{
		int minVal = 1000;
		int index = 0;	
		for(int i=0;i<=rear;i++)
		{
			if(cost[myQueue[i]] < minVal)
			{
				index = i;
				minVal = myQueue[i];
			
			}
		}
		
	for(int i = index;i<rear;i++)
	{
		myQueue[i] = myQueue[i+1];
	}
	myQueue[rear] = 0;
	rear--;
	return minVal;
	
	}
	
}


void create_graph()
{

	N=6; // let's say we have 6 points
	maxVertices = N*(N-1);
	
	for(int i=0;i<10;i++) // let's say 10 vertices;
	{
		int origin, dest;
		
		scanf("%d%d", &origin,&dest);
		
		adjMat[origin][dest] = 1;
	
	
	}

}





int main(int argc, char *argv[]) 
{	
  int a[10]= {1,2,9,5,4,6,7,8,3,0};
  
 //create_graph();
 
 //test data
 adjMat[1][2]= 7;
 adjMat[1][3]= 9; 
 adjMat[1][6]= 14; 
 adjMat[2][3]= 10; 
 adjMat[3][4]= 11;
 adjMat[4][5]= 6;
 adjMat[6][5]=9;
 
 int startPoint = 1;
 int destPoint = 5;

 for(int i=1;i<=N;i++)
 {
	 cost[i] = INFINITY; 
 }
 
 cost[startPoint] = 0;
 qpush(startPoint); 
 int visitedValue= 1;
  
 while(1)
 {
	 int current = qpop();	 	 
	 if(current == -6) break;
	 
	 if(visited[current] == 0)
	 {
		visited[current] = visitedValue;
	 
		for(int i=1;i<=N;i++)
		{
			if(adjMat[current][i] !=0 and visited[i] == 0)
			{		
				qpush(i);
				int temp = cost[current] + adjMat[current][i];
				if(temp < cost[i])
				{
					cost[i] = temp;
				}
			} 
		}
	 
	 }
 }
 
 for(int i=1;i<=N;i++)
 {
	 printf("cost [ %d ] = %d \n", i, cost[i]);
 }
 
 //printing the path;
 
 int temp = destPoint;
 int path[N];
 int index=0;
 path[index++] = destPoint;

 while(temp!=startPoint)
 {
	 for(int i=1;i<=N;i++)
	 {
		 
		 if(adjMat[i][temp] != 0)
		 {
			 int check =  cost[temp] - adjMat[i][temp];
			 if(check == cost[i])
			 {
				 temp = i;
				 path[index++] = temp;
				 break;
			 }
		 }
	 }
 }
 
 cout << "path: "; 
 for(int i=(index-1);i>=0;i--)
 {
	 cout << "->" << path[i] ;
 }
 
 cout << endl;
 
 
 
  return 0;	
	
}
