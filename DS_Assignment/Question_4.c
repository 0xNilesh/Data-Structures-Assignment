
/********************Code by Nilesh Gupta****************/
/********************BST(String)*****************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char data[100];
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node* FirstNode()
{
	char data[100];
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	if(temp==NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
	printf("\nEnter data for root node : ");
	fflush(stdin);
	gets(data);
	strcpy(temp->data,data);
	temp->left=NULL;
	temp->right=NULL;
return temp;
}

Node* Insertion(Node *temp,char* ch)               
{
	if(temp!=NULL && strcmp(temp->data,ch)>0)
		temp->left=Insertion(temp->left,ch);
	else if(temp!=NULL && strcmp(temp->data,ch)<0)
		temp->right=Insertion(temp->right,ch);
	else
	{
		temp=(Node*)malloc(sizeof(Node));
		if(temp==NULL)
	    {
	        printf("Memory not allocated");
	        return NULL;
	    }
		strcpy(temp->data,ch);
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
}

void preorder(Node *temp)
{
	if(temp)
	{
		printf("%s ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(Node *temp)
{
	if(temp)
	{
		inorder(temp->left);
		printf("%s ",temp->data);
		inorder(temp->right);
	}
}

void postorder(Node *temp)
{
	if(temp)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%s ",temp->data);
	}
}

int main()
{
	char ch[100];
	int res=0;
	Node *root=FirstNode();
    while(1)
    {
        printf("\nPress \n'1' to insert a string\n'2' to traverse preorder\n'3' to traverse inorder\n'4' to traverse postorder\n'5' if you wanna exit\n");
        scanf("%d",&res);
        fflush(stdin);
        switch(res)
        {
            case 1 : printf("\nEnter string : ");
            		 scanf("%s",&ch);
            		 Insertion(root,ch);
                     break;

            case 2 : preorder(root);
                     break;

            case 3 : inorder(root);
                     break;

            case 4 : postorder(root);
                     break;

            case 5 : exit(1);

            default : printf("\nYou entered wrong choice !!!!!!!!!!!!");
                      break;
        }           
    }
}