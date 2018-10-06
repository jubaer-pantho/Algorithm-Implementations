//minimum spanning tree Algorithm (Kruskal)
#include<stdio.h>
#include<iostream>

#define INFINITY 9999
#define MAX 100 
using namespace std;

int parent[MAX];
int visited[MAX];
int N=7;
int maxVertices;

int result[MAX];

int find(int a)
{
	int temp1=a;
	int temp2;
	while(temp1)
	{
		temp2 = parent[temp1];		
		if (temp2 == temp1)
		{
			break;
		}		
		temp1 = temp2;
	}
	return temp2;
}

int source[MAX];
int destination[MAX];
int edgeVal[MAX];

int unionFunc(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);
	
	if(parent[a] == 0 || parent[b] == 0)
	{
		if(a<b)
		{
			parent[a] = parent[b] = a;
			
		}
		else
		{
			parent[a] = parent[b] = b;
		}
	}
	else if(rootA < rootB)
	{
		parent[b] = parent[a];
	}
	else if(rootA > rootB)
	{
		parent[a] = parent[b];
	}
	else if(rootA == rootB)
	{
		//do nothing
		return 0;
	}
	
	visited[a] = 1;
	visited[b] = 1;	
	return 1;
}

void create_graph()
{
	N=7; // let's say we have 6 points
	maxVertices = N*(N-1);
	for(int i=0;i<10;i++) // let's say 10 vertices;
	{
		scanf("%d%d%d", &source[i],&destination[i], &edgeVal[i]);
	}
}

int main(int argc, char *argv[]) 
{	
// sample graph
//use create graph function to generate a different graph
source[1]= 1;
destination[1] = 2;
edgeVal[1] = 7;

source[2]= 1;
destination[2] = 3;
edgeVal[2] = 5;

source[3]= 1;
destination[3] = 6; 
edgeVal[3] = 14;

source[4]= 3;
destination[4] = 4;
edgeVal[4] = 11;

source[5]= 6;
destination[5] = 5; 
edgeVal[5] = 9;

source[6]=4;
destination[6] = 5; 
edgeVal[6] = 6;

source[7]= 2;
destination[7] = 3; 
edgeVal[7] = 10;

  for(int i=1;i<=7;i++)
 {
	 printf("source, desitnation edgeVal %d   %d   %d\n", source[i], destination[i], edgeVal[i] );	 
 }

cout << "\n\n\n";

 for(int i=1;i<7;i++)
 {
	 for(int j=1;j<7-i+1;j++)
	 {
		 if(edgeVal[j] > edgeVal[j+1])
		 {
			 int temp = edgeVal[j];
			 edgeVal[j] = edgeVal[j+1];
			 edgeVal[j+1] = temp;
			 
			 
			 int temp2 = source[j];
			 source[j] = source[j+1];
			 source[j+1] = temp2;
			 
			 int temp3 = destination[j];
			 destination[j] = destination[j+1];
			 destination[j+1] = temp3; 
		 }
	 }
}
 
  for(int i=1;i<=7;i++)
 {
	 printf("new source, desitnation edgeVal %d   %d   %d\n", source[i], destination[i], edgeVal[i] );
	 //cout << "edgeval " << edgeVal[i] << "\n";	 
 }
 cout <<"\n\n";

 int count=0;
 for(int i=1;i<=7;i++)
 {
/* 	    if(i==3)
     	{
				 printf("\nparent 1 : %d, parent2 : %d \n", parent[source[i]], parent[destination[i]]);
				 printf("soure point = %d destination point = %d\n\n", source[i],  destination[i]);
		}
*/	 	 
		int resultEdge = unionFunc(source[i], destination[i]);
		
		if(resultEdge)
		{
			result[i] = 1;
			count++;			
		}
	 
	 if(count==5) break;

 }

 for(int i=1;i<=N;i++)
 {
	 if(result[i] ==1){
		cout <<"no. " << i;
		printf(" MST edge: source: %d  destination:  %d  value: %d\n", source[i], destination[i], edgeVal[i] );
	 }
 }
 
  return 0;		
}
