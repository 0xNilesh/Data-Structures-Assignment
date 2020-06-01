
/********************Code by Nilesh Gupta****************/
/********************Merge Sort (String)*****************/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

char B[80];

void merge(char A[],int l,int m,int h) //Merges the lists
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
	for(int q=l;q<=h;q++)               //copy merged values to original array
		A[q]=B[q];
}

void merge_sort(char A[],int l, int h ) //Mergesort 
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
	char str[100];
	printf("Enter the String\n");
	fflush(stdin);
	gets(str);
	int i=0;
	int n=strlen(str);
	while(str[i]!='\0')
	{
		if(isupper(str[i]))
			str[i]=tolower(str[i]);      //converting all characters to lowercase
		i++;
	}	
	merge_sort(str,0,n-1);
	printf("Sorted string : ");
	for(int i=0;i<n;i++)
	{
		if(str[i]==' ') 
			continue;
		printf("%c",str[i]);
	}
	return 0;
}