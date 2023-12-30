#include<stdio.h>
#include<stdlib.h>
int Find(int* arr,int low,int high,int key)
{
	int i;
	for(i = low ; i <= high ; i++)
	{
		if(arr[i] == key)
			return i;
	}
	return -1;
}
int rear = -1;
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
	int n,ref,search = 0;
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
	printf("Enter the page references\n");
	for(i = 0; i < ref; i++)
	{
		scanf("%d",&page_ref[i]);
	}
	for(i = 0; i < ref; i++)
	{
		search = Find(page,0,n-1,page_ref[i]);
		if(search != -1)
		{
			printf("%d: Hit\n",page_ref[i]);
		}
		else
		{
			if(rear != n-1)
			{
				page[++rear] = page_ref[i];
			}
			else
			{
				int  refer = 0,index = 0,far_refer = 0;
				far_refer = Find(page_ref,i+1,ref-1,page[0]);		
				if(far_refer != -1)
				{
					for(int k = 0 ; k < n ; k++)
					{
						refer = Find(page_ref,i+1,ref-1,page[k]);
						if(refer == -1)
						{
							index = k;
							break;
						}
						else
						{
							if(far_refer < refer)
							{
								far_refer = refer;
								index = k;
							}
						}
					}
				}
				page[index] = page_ref[i];
			}
			printf("%d: Miss ",page_ref[i]);
			display(page,n);		
		}
	}
	return 0;
}
