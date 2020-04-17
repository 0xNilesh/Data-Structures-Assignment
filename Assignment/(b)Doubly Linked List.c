
/***********Code by Nilesh Gupta ;) ************/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head;

void createnode(int n) //Creates a doubly linked list
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
     head->prev=NULL;
     head->next=NULL;
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
    		newnode->next=NULL;
    		newnode->prev=temp;
    		temp->next=newnode;
    		temp=temp->next;
 		}
}

void deletefromvalue(int value) //Deletes the value entered by user from the list
{
    struct node *temp=head;
    while(temp->next->data != value)
        temp=temp->next;
    struct node *temp1=temp->next->next;
    free(temp->next);
    temp->next=temp1;
}

void traverse()     //Traverses the list
{
	struct node *temp=head;
    printf("\nYour list is : ");
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int main() //Driver Function
{
	int n,index,value;
    printf("\nEnter value of n : ");
    scanf("%d",&n);
    createnode(n);
    traverse();

    printf("\nEnter data which you want to delete : ");
    scanf("%d",&value);
    deletefromvalue(value);
    traverse();
return 0;
}