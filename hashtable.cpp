// simple hashtable
// Md Jubaer Hossain Pantho
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define SIZE 50

struct dataSet{
	int data;
	int key;
	};
	
struct dataSet* DataItem[200]; 
struct dataSet* tempItem;

int hashFunction(int key)
{
	return key%SIZE;
}

struct dataSet *search(int key)
{
	int searchKey = hashFunction(key);

	while(DataItem[searchKey] != NULL)
	{
		if(DataItem[searchKey]->key == key)
		{
			return DataItem[searchKey];	
		}
		searchKey++;		
		searchKey%=SIZE;
	}	
	return NULL;
	
}


void insert(int keyVal, int dataVal)
{
	int indexKey = hashFunction(keyVal);
	
   struct dataSet *item = (struct dataSet*) malloc(sizeof(struct dataSet));
   item->data = dataVal;  
   item->key = keyVal;

	while(DataItem[indexKey] != NULL)
	{
		indexKey++;		
		indexKey %= SIZE;
	}
	DataItem[indexKey]= item;
}

void deleteItem(struct dataSet* item)
{
	int indexKey = hashFunction(item->key);
	
	while(DataItem[indexKey]->key != item->key)
	{
		indexKey++;
		indexKey%=SIZE;
	}
	
	DataItem[indexKey]->key = -1;
	DataItem[indexKey]->data = -1;
}

	
void displayFunc() {
   for(int i = 0; i<SIZE; i++) 
   {
      if(DataItem[i] != NULL)
         printf(" (key: %d, data: %d)\n",DataItem[i]->key,DataItem[i]->data);
      else
         printf(" --\n");
   }
	
   printf("\n");
}
	
int main(int argc, char* argv[])
{
   tempItem = (struct dataSet*) malloc(sizeof(struct dataSet));
   tempItem->data = -1;  
   tempItem->key = -1;
  
   insert(11, 27);
   insert(20, 73);
   insert(29, 87);
   insert(45, 25);
   insert(14, 32);
   insert(37, 47);
   insert(13, 79);
   insert(32, 85);
   
   displayFunc();

   struct dataSet* cursor;
   
   
   cursor = search(32);

   if(cursor != NULL) 
   {
      printf("Data found: ( %d )\n", cursor->data);
   } 
   else 
   {
      printf("Data not found\n");
   }

   deleteItem(cursor);
   cursor = search(32);

   if(cursor != NULL)
   {
      printf("Data found: (%d)\n", cursor->data);
   }
   else 
   {
      printf("Data not found\n");
   }	
   
return 0;
}
