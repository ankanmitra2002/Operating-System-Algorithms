#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int size = 0,num = 0;
typedef struct node Queue;
struct node
{
	int p_id;
	int arrival_time;
	int burst_time;
};
Queue *heap;
void swap(Queue *x, Queue *y)
{
	Queue temp = *x;
	*x = *y;
	*y = temp;
}
void down_heapify(int i)
{
	int small = i;
	int lchild = 2*i + 1;
	int rchild = 2*i + 2;
	if((lchild < size) && (heap[lchild].burst_time < heap[small].burst_time))
	    small = lchild;
	if((rchild < size) && (heap[rchild].burst_time < heap[small].burst_time))
	    small = rchild;
	if(small != i)
	{
		swap(&heap[i],&heap[small]);
		down_heapify(small);
	}
}
void up_heapify(int i)
{
	while(i != 0 && heap[(i-1)/2].burst_time > heap[i].burst_time)
	{
		swap(&heap[(i-1)/2],&heap[i]);
		i = (i-1)/2;
	}
}
void enQueue(Queue item)
{
	if(size == num)
	{
		printf("Heap is full\n");
		return;
	}
	heap[size++] = item;
	up_heapify(size-1);
}
void deQueue()
{
	if(size == 0)
	{
		printf("No element in heap\n");
		return;
	}
	swap(&heap[0],&heap[size-1]);
	size--;
	down_heapify(0);
}
int main()
{
	int i,time,duration;
	printf("Enter the number of processes: ");
	scanf("%d",&num);
    Queue *process = (Queue *) malloc (num*sizeof(Queue));
    heap = (Queue *)malloc(num*sizeof(Queue));
    duration = 0;
    printf("Enter process no,arrival time and burst time:\n");
    for(i = 0 ; i < num ; i++)
    {
    	scanf("%d %d %d",&process[i].p_id,&process[i].arrival_time,&process[i].burst_time);
    	duration += process[i].burst_time;
	}
	Queue dequeued_element,prev;
	i = 0;
	prev.p_id = -1;
	for(int time = 0;time <= duration;time++)
	{
		if(time == process[i].arrival_time)
		{
			enQueue(process[i]);
			if(i < num-1)
			{
				i++;
			}
		}
		if(prev.p_id == -1 && size == 1)
		{
			printf("%d: Process %d start\n",time,heap[0].p_id);
		}
		else if(heap[0].burst_time == 0 && size != 1)
		{
			deQueue();
			printf("%d: Process %d end process %d start\n",time,prev.p_id,heap[0].p_id);
		}
		else if(heap[0].burst_time == 0 && size == 1)
		{
			deQueue();
			printf("%d: Process %d end\n",time,prev.p_id);
			prev.p_id = -1;
		}
		else if(prev.p_id != -1 && prev.p_id != heap[0].p_id)
		{
			printf("%d: Process %d preempt(remaining time %d) process %d start\n",time,prev.p_id,prev.burst_time,heap[0].p_id);
		}
		heap[0].burst_time--;
		prev = heap[0];
	}
    return 0;
}
