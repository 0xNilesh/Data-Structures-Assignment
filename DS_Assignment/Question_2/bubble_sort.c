
/********************Code by Nilesh Gupta****************/
/********************Bubble Sort*****************/
#include<stdio.h>

int main()
{
	int n;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    int ar[n];
    printf("\nEnter the elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&ar[i]);
	int fg=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			fg=0;
			if(ar[j]>ar[j+1])        
			{
				int t=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=t;
				fg=1;
			}
		}
		if(!fg)              
			break;
	}

	printf("\nSorted Array : \n");
    for(int i=0;i<n;i++)
        printf("%d ",ar[i]);
}