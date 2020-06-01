
/********************Code by Nilesh Gupta****************/
/********************Quick Sort*****************/
#include<stdio.h>

void swap(int *x,int *y) 
{    
	int temp=*x;    
	*x=*y;    
	*y=temp; 
} 

int partition(int *arr, int low, int high)          //Returns the index at which partition is done
{
	int i=low,j,pi;                                 //pi is pivot element
	pi=arr[high];
	for(int j=low;j<high;j++)
	{
		if(arr[j]<=pi)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[high]);
	return i;
}

void quick_sort(int *arr, int low, int high)        //Quick Sort
{
	int pi;
	if(low<high)
	{
		pi=partition(arr,low,high);
		quick_sort(arr,pi+1,high);
		quick_sort(arr,low,pi-1);
	}
}

int main()             							    //Driver Function
{
	int i=0,j,n,pi;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quick_sort(arr,0,n-1);
	printf("\nSorted Array : \n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
}