//DFS

#include<stdio.h>
#include<iostream>

#define MAX 100 
using namespace std;

int adjMat[MAX][MAX];

int myStack[200];
int N=6;
int maxVertices;
int top = -1;

int visited[MAX];

void spush(int q)
{
	top++;
	myStack[top] = q;	
}

int spop()
{
	if(top==-1)
	{
		printf("stack is empty\n");		
		return -6;
	}
	else
	{
		return myStack[top--];
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
 
 adjMat[1][2]= 1;
 adjMat[1][3]= 1; 
 adjMat[1][4]= 1; 
 adjMat[2][3]= 1; 
 adjMat[2][4]= 1;
 adjMat[3][5]= 1;
 adjMat[3][2]= 1; 
 adjMat[3][4]= 1; 
 adjMat[5][6]=1;
 
 
 int initialPoint = 1;
 
 spush(1);
 
 int visitedValue= 1;
  
 while(1)
 {

	 int current = spop();	 	 
	 if(current == -6) break;
	 
	 if(visited[current] == 0)
	 {
		visited[current] = visitedValue;
		visitedValue++;
	 
		for(int i=1;i<=N;i++)
		{
			if(adjMat[current][i] == 1 and visited[i] == 0)
			{		
				spush(i);
			} 
		}
	 
	 }
 }
 
 for(int i=1;i<=N;i++)
 {
	 printf("visited [ %d ] = %d \n", i, visited[i]);
	 
	 }
  
  return 0;	
	
}


