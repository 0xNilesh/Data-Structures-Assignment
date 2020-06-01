
/********************Code by Nilesh Gupta****************/
/********************Insertion Sort*****************/
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
    for(int i=1;i<n;i++)
    {
        int j=i-1,last_element=ar[i],ind=i;
        while(last_element<ar[j] && j>=0)
        {
            int temp=ar[j];
            ar[j]=last_element;
            ar[i]=temp;
            i--;
            j--;
        }
        i=ind;
    }
    printf("\nSorted Array : \n");
    for(int i=0;i<n;i++)
        printf("%d ",ar[i]);
}
