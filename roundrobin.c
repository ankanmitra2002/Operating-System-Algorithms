#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define SIZE 100
static int front = -1;
static int rear = -1;
typedef struct node Queue;
struct node
{
	int p_id;
	int burst_time;
};
void enqueue(Queue *queue,int no, int time)
{
    if(rear == SIZE - 1)
    	printf("Queue is full\n");
    else
    {
    	queue[++rear].p_id = no;
    	queue[rear].burst_time = time;
	}

}

Queue dequeue(Queue *queue)
{
    if(front == rear)
	{
		Queue item;
		item.p_id = -1;
    	return item;
	}
    else
    {
    	return queue[++front];
	}
}
int main()
{
	int num,quantum,no,time;
	printf("Enter the number of process: ");
	scanf("%d",&num);
	printf("Enter the time quantum: ");
	scanf("%d",&quantum);
    Queue *queue = (Queue*)malloc(SIZE*sizeof(Queue));
    int* remain = (int*)malloc(num*sizeof(int));
    Queue dequeued_element;
    Queue prev;
    printf("Enter process number and burst time\n");
    for(int i = 0 ; i < num ; i++)
    {
    	scanf("%d %d",&no,&time);
    	enqueue(queue,no,time);
    	remain[i] = time;
	}
	int count = 0;
	dequeued_element = dequeue(queue);
	prev = dequeued_element;
	time = 0;
	printf("%d : Process %d start\n",time,dequeued_element.p_id);
	while(1)
	{
		if(front != rear)
			dequeued_element = dequeue(queue);
		if(prev.burst_time > quantum)
		{
			time += quantum;
			prev.burst_time = prev.burst_time - quantum;
			printf("%d : Process %d preempt Process %d start\n",time,prev.p_id,dequeued_element.p_id);
			enqueue(queue,prev.p_id,prev.burst_time);
		}
		else if(prev.burst_time <= quantum && prev.p_id != dequeued_element.p_id)
		{
			time += prev.burst_time;
			printf("%d : Process %d end Process %d start\n",time,prev.p_id,dequeued_element.p_id);
		}
		else
		{
			time += prev.burst_time;
			printf("%d : Process %d end\n",time,prev.p_id);
			break;
		}
		if(prev.p_id != dequeued_element.p_id)
		{
			prev = dequeued_element;
		}	
	}
    return 0;
}
