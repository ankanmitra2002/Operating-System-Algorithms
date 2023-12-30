#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int getMinSeekTime(int* arr,int n,int pivot,int* visited)
{
	int min = INT_MAX,index = 0;
	int seektime;
	for(int i = 0 ; i < n ; i++)
	{
		if(!visited[i])
		{
			seektime = abs(arr[i]-pivot);
			if(min > seektime)
			{
				min = seektime;
				index = i;
			}
		}
	}
	return index;
}
int main()
{
	int head,ref,index = 0;
	printf("Enter the head start position: ");
	scanf("%d",&head);
	printf("Enter the number of disk refernces: ");
	scanf("%d",&ref);
	int* movement = (int*)malloc(ref*sizeof(int));
	int* visited = (int*)calloc(ref,sizeof(int));
	int seektime;
	printf("Enter the disk refernces: ");
	for(int i = 0 ; i < ref ; i++)
	{
		scanf("%d",&movement[i]);
	}
	int move = head;
	for(int i = 0 ; i < ref ; i++)
	{
		index = getMinSeekTime(movement,ref,move,visited);
		printf("%d: %d moves\n",movement[index],abs(movement[index]-move));
		visited[index] = 1;
		move = movement[index];
	}
	
	return 0;
}
