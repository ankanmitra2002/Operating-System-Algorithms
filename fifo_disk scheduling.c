#include<stdio.h>
#include<stdlib.h>

int main()
{
	int head,ref;
	printf("Enter the head position: ");
	scanf("%d",&head);
	printf("Enter the number of refernces: ");
	scanf("%d",&ref);
	int* movement = (int*)malloc(ref*sizeof(int));
	for(int i = 0 ; i < ref ; i++)
	{
		scanf("%d",&movement[i]);
	}
	int move = head;
	for(int i = 0 ; i < ref ; i++)
	{
		printf("%d: %d moves\n",movement[i],abs(movement[i]-move));
		move = movement[i];
	}
	
	return 0;
}
