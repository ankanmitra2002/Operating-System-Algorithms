#include<stdio.h>
#include<stdlib.h>
int Find(int* arr,int n,int key)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		if(arr[i] == key)
			return 1;
	}
	return 0;
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

/* function to enqueue */
void enQueue(int* queue,int id,int num)
{
	rear = (rear+1)%num;
	queue[rear] = id;
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
int main()
{
	int n,ref;
	printf("Enter the number of page frames\n");
	scanf("%d",&n);
	int* page = (int*)malloc(n*sizeof(int));
	int i;
	for(i = 0; i < n; i++)
	{
		page[i] = -1;
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
		if(Find(page,n,page_ref[i]))
		{
			printf("%d: Hit\n",page_ref[i]);
		}
		else
		{
			printf("%d: Miss ",page_ref[i]);
			enQueue(page,page_ref[i],n);		
			display(page,n);			
		}
	}
	return 0;
}
