#include<stdio.h>
#include<stdlib.h>
int Find(int* arr,int n,int key)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		if(arr[i] == key)
			return i;
	}
	return -1;
}
int front = -1;/* front,rear are set as -1 */
int rear = -1;
void QueueFull()
{
	printf("Queue is Full\n");
}
void QueueEmpty()
{
	printf("Queue is empty\n");
}


void display(int* arr,int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int getMax(int* time,int n)
{
	int max = time[0],index = 0;
	for(int i = 1 ; i < n ; i++)
	{
		if(max < time[i])
		{
			max = time[i];
			index = i;
		}
	}
	return index;
}
void increment(int* time,int n)
{
	for(int i = 0 ; i<n;i++)
	{
		time[i]++;
	}
}
int main()
{
	int n,ref,index,search = 0;
	printf("Enter the number of page frames\n");
	scanf("%d",&n);
	int* page = (int*)malloc(n*sizeof(int));
	int i;
	int* time = (int*)malloc(n*sizeof(int));
	for(i = 0; i < n; i++)
	{
		page[i] = -1;
		time[i] = 1;
	}
	printf("Enter the number of page references\n");
	scanf("%d",&ref);
	int* page_ref = (int*)malloc(ref*sizeof(int));
	for(i = 0; i < ref; i++)
	{
		scanf("%d",&page_ref[i]);
	}
	for(i = 0; i < ref; i++)
	{
		search = Find(page,n,page_ref[i]);
		if(search != -1)
		{
			printf("%d: Hit\n",page_ref[i]);
			increment(time,n);
			time[search] = 1;
			//display(time,n);
		}
		else
		{
			printf("%d: Miss ",page_ref[i]);
			index = getMax(time,n);
			rear = index;
			page[rear] = page_ref[i];
			increment(time,n);	
			time[rear] = 1;	
			display(page,n);			
		}
	}
	return 0;
}
