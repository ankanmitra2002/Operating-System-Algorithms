#include<stdio.h>
#include<stdlib.h>
static int front = -1;
static int rear = -1;
typedef struct node Queue;
struct node
{
	int p_id;
	int burst_time;
};
void enqueue(Queue *queue,int no, int time,int num)
{
    if(rear == num - 1)
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
	int num,no,time;
	printf("Enter the number of process: ");
	scanf("%d",&num);
    Queue *queue = (Queue*)malloc(num*sizeof(Queue));
    Queue dequeued_element;
    Queue prev;
    printf("Enter process no. and burst time:\n");
    for(int i = 0 ; i < num ; i++)
    {
    	scanf("%d %d",&no,&time);
    	enqueue(queue,no,time,num);
	}
	dequeued_element = dequeue(queue);
	time = 0;
    prev = dequeued_element;
	printf("%d : Process %d start\n",time,dequeued_element.p_id);
	for(int i = 0 ; i < num ; i++)
	{
		time += prev.burst_time;
		if(i == num - 1)
			printf("%d : Process %d end\n",time,prev.p_id);
		else
		{
			dequeued_element = dequeue(queue);
			printf("%d : Process %d end Process %d start\n",time,prev.p_id,dequeued_element.p_id);
		}
		prev = dequeued_element;
	}
    return 0;
}
