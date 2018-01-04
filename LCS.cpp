//minimum spanning tree Algorithm (Kruskal)
#include<stdio.h>
#include<iostream>
#include<string.h>

#define INFINITY 9999
#define MAX 100 
using namespace std;

int parent[MAX];
int visited[MAX];
int N=7;
int maxVertices;

int result[MAX];






int main(int argc, char *argv[]) 
{
	
	char string2[] = "BDCABA";
	char string1[] = "ABCBDAB";
	
	
	int len1, len2;
	
	len1 = strlen(string1);
	len2 = strlen(string2);
	
	int mat[len1+1][len2+1];
	
	
	for(int i=0;i<(len1+1); i++)
		for(int j=0;j<(len2+1); j++)
			mat[i][j] =0;
	
	for(int i=1;i<(len1+1); i++)
	{
		for(int j=1;j<(len2+1); j++)
		{
			if(string1[i-1] == string2[j-1])
			{
				mat[i][j] = mat[i-1][j-1] +1;
			}
			else
			{
				mat[i][j] = mat[i-1][j]>mat[i][j-1]? mat[i-1][j]: mat[i][j-1];
			}
		}
	}
		
	for(int i=0;i<(len1+1); i++)
	{
		for(int j=0;j<(len2+1); j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	
	int temp= mat[len1][len2];
	int i= len1;
	int j= len2;
	
	cout << endl;
	
	
	while(temp)
	{
		if(mat[i][j-1] == mat[i][j])
		{
			temp = mat[i][j-1];
			j=j-1;
		}
		else if(mat[i-1][j] == mat[i][j])
		{
			temp = mat[i-1][j];
			i = i-1;
		}
		else
		{
			cout << string2[j-1] << "\n";
			i=i-1;
			j=j-1;
			temp = mat[i][j];
		}
	}
	
	
	cout << "result=" << mat[len1][len2] << endl; 

}
