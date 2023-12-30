#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef struct node Queue;
struct node
{
	int p_id;
	int burst_time;
};
void swap(Queue *x, Queue *y)
{
	Queue temp = *x;
	*x = *y;
	*y = temp;
}
void heapify(Queue *arr,int n,int i)
{
	int small = i;
	int lchild = 2*i + 1;
	int rchild = 2*i + 2;
	if((lchild < n) && (arr[lchild].burst_time < arr[small].burst_time))
	    small = lchild;
	if((rchild < n) && (arr[rchild].burst_time < arr[small].burst_time))
	    small = rchild;
	if(small != i)
	{
		swap(&arr[i],&arr[small]);
		heapify(arr,n,small);
	}
}
void buildheap(Queue *arr,int n)
{
	int last_internal_node = (n/2) - 1;
	int i;
	for(i = last_internal_node ; i >= 0 ; i--)
	    heapify(arr,n,i);
}
Queue delheap(Queue *queue,int n)
{
	Queue element = queue[0];
	swap(&queue[0],&queue[n-1]);
	heapify(queue,n-1,0);
	return element;
}
int main()
{
	int num;
	printf("Enter the number of process: ");
	scanf("%d",&num);
    Queue *queue = (Queue *)malloc(num*sizeof(Queue));
    Queue dequeued_element;
    Queue prev;
    printf("Enter process no. and burst time:\n");
    for(int i = 0 ; i < num ; i++)
    {
    	scanf("%d %d",&queue[i].p_id,&queue[i].burst_time);
	}
	buildheap(queue,num);
	dequeued_element = delheap(queue,num);
	int time = 0;
    prev = dequeued_element;
	printf("%d : Process %d start\n",time,dequeued_element.p_id);
	for(int i = num -1  ; i >= 0 ; i--)
	{
		time += prev.burst_time;
		if(i == 0)
			printf("%d : Process %d end\n",time,prev.p_id);
		else
		{
			dequeued_element = delheap(queue,i);
			printf("%d : Process %d end Process %d start\n",time,prev.p_id,dequeued_element.p_id);
		}
		prev = dequeued_element;
	}
    return 0;
}
