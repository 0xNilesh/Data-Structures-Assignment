
/********************Code by Nilesh Gupta****************/
/********************Merge Sort*****************/
#include<stdio.h>

int B[80];

void merge(int A[],int l,int m,int h) //Merges the lists
{
	int i=l,j=m+1,k=l;
	while(i<=m && j<=h)
	{
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
	}
	for(;i<=m;i++)
		B[k++]=A[i];
	for(;j<=h;j++)
		B[k++]=A[j];
	for(int q=l;q<=h;q++)             //copy merged values to original array
		A[q]=B[q];

}

void merge_sort(int A[],int l, int h ) //Mergesort 
{
	if(l<h)
	{
		int m=l + (h-l)/2;
		merge_sort(A,l,m);
		merge_sort(A,m+1,h);
		merge(A,l,m,h);
	}
}

int main()                             //Driver Function
{
	int n;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int A[n];
	printf("\nEnter the elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	merge_sort(A,0,n-1);
	printf("\nSorted Array : \n");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
}