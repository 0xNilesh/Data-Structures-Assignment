
/***********Code by Nilesh Gupta ;) ************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head;

void createnode(int n) //Creates a singly linked list
{
     int data;
     head=(struct node*)malloc(sizeof(struct node));
     if(head==NULL)
     {
         printf("Memory not allocated");
         return;
     }
     printf("\nEnter node data : ");
     scanf("%d",&data);
     head->data=data;
     head->link=NULL;
     struct node *temp=head;
    	for(int i=2;i<=n;i++)
 	    {
        	struct node *newnode=(struct node*)malloc(sizeof(struct node));
        	if(newnode==NULL)
   			{
        		printf("Memory not allocated");
        		break;
    		}
    		printf("\nEnter node data : ");
    		scanf("%d",&data);
    		newnode->data=data;
    		newnode->link=NULL;
    		temp->link=newnode;
    		temp=temp->link;
 		}
}

void traverse() //Traverses the list
{
	struct node *temp=head;
    printf("\nYour list is : ");
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
}

void deletefromvalue(int value) //Deletes a value from the list
{
    struct node *temp=head;
    while(temp->link->data != value)
        temp=temp->link;
    struct node *temp1=temp->link->link;
    free(temp->link);
    temp->link=temp1;
}

int main() //Driver Function
{
    int n,index,value;
    printf("\nEnter value of n : ");
    scanf("%d",&n);
    createnode(n);
    traverse();

    printf("\nEnter integer which you want to delete : ");
    scanf("%d",&value);
    deletefromvalue(value);
    traverse();
return 0;
}