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
	int n,ref,misscount = 0;
	int mem_access,page_fault;
	printf("Enter memory access time and page fault time\n");
	scanf("%d %d",&mem_access,&page_fault);
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
	printf("Enter the page references\n");
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
			misscount++;		
		}
	}
	double effect_access = (double)((1-((double)misscount/ref))*mem_access + ((double)misscount/ref)*page_fault);
	printf("Effective memory access time: %f",effect_access);
	return 0;
}
