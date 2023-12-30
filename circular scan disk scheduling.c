#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node
{
	int* arr;
	int lsize;
	int rsize;
}Node;
void merging(int* arr,int left,int mid,int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int* copy = (int*)malloc((right - left + 1)*sizeof(int));
    while (( i <= mid ) && ( j <= right ))
    {
        if ( arr[i] < arr[j])
        {
            copy[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            copy[k] = arr[j];
            k++;
            j++;
        }
    }
    while ( i <= mid )
    {
        copy[k] = arr[i];
        k++;
        i++;
    }
    while ( j <= right )
    {
        copy[k] = arr[j];
        k++;
        j++;
    }
    for ( int i = 0 ; i <= (right - left) ; i++)
    {
        arr[left+i] = copy[i];
    }
    free(copy);/* freeing the extra space */
}
/* recursive merge sort function */
void merge_sort(int* arr,int left,int right)
{
    int mid;
    if ( left < right )
    {
        mid = (left + right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merging(arr,left,mid,right);
    }
}
Node* partition(int* arr,int n,int pivot)
{
	Node* element = (Node*)malloc(sizeof(Node));
	element->arr = (int*)malloc(n*sizeof(int));
	int j = 0,k = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(arr[i] <= pivot )
		{
			element->arr[j++] = arr[i];
		}
	}
	element->lsize = j;
	element->rsize = n-j;
	for(int i = 0 ; i < n ; i++)
	{
		if(arr[i] > pivot )
		{
			element->arr[j++] = arr[i];
		}
	}
	merge_sort(element->arr,0,element->lsize -1);
	merge_sort(element->arr,element->lsize,n-1);
	return element;
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
	int head,ref,index = 0;
	char direction = 'l';
	int lower_lim,upper_lim;
	printf("Enter the lower and upper limits: ");
	scanf("%d %d",&lower_lim,&upper_lim);
	printf("Enter the head position: ");
	scanf("%d",&head);
	printf("Enter the number of refernces: ");
	scanf("%d",&ref);
	fflush(stdin);
	printf("Enter the direction(l for left/r for right): ");
	scanf("%c",&direction);
	int* movement = (int*)malloc(ref*sizeof(int));
	for(int i = 0 ; i < ref ; i++)
	{
		scanf("%d",&movement[i]);
	}
	Node* partitioning = (Node*)malloc(sizeof(Node));
	partitioning = partition(movement,ref,head);
	int* arr = partitioning->arr;
	int leftsize = partitioning->lsize;
	int rightsize = partitioning->rsize;
//	printf("%d %d",leftsize,rightsize);
//	display(arr,ref);
	int move = head;
	if(direction == 'l')
	{
		for(int i = leftsize-1 ; i >= 0 ; i--)
		{
			printf("%d: %d moves\n",arr[i],(move-arr[i]));
			move = arr[i];
		}
		if(arr[0] != lower_lim)
		{
			printf("%d: %d moves\n",lower_lim,(move-lower_lim));
		}
		printf("%d: %d moves\n",upper_lim,upper_lim - lower_lim);
		move = upper_lim;
		for(int i = rightsize-1 ; i >= 0 ; i--)
		{
			printf("%d: %d moves\n",arr[i+leftsize],(move-arr[i+leftsize]));
			move = arr[i+leftsize];
		}
	}
	else
	{
		for(int i = 0 ; i < rightsize ; i++)
		{
			printf("%d: %d moves\n",arr[i+leftsize],(arr[i+leftsize]-move));
			move = arr[i+leftsize];
		}
		if(arr[ref-1] != upper_lim)
		{
			printf("%d: %d moves\n",upper_lim,(upper_lim-move));
		}
		printf("%d: %d moves\n",lower_lim,upper_lim - lower_lim);
		move = lower_lim;
		for(int i = 0 ; i < leftsize ; i++)
		{
			printf("%d: %d moves\n",arr[i],(arr[i]-move));
			move = arr[i];
		}
	}	
	return 0;
}
