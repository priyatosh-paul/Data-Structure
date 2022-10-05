#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *start=NULL;

NODE * create_node()
{
	NODE *temp;
//	temp=(NODE *)malloc(sizeof(NODE));
	temp = new NODE;
	temp->next=NULL;
	return temp;
}

void add_first(int data)
{
	NODE *newnode;
	newnode=create_node();
	newnode->data=data;
	if(start==NULL)
	{
		start=newnode;
	}//if list is empty
	else
	{
		newnode->next=start;
		start=newnode;
	}
}

void add_last(int data)
{
	NODE *newnode,*trav;
	newnode=create_node();
	newnode->data=data;
	if(start==NULL)
	{
		start=newnode;
	}//list is empty
	else
	{
		trav=start;
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}//traverse till reach to last node

		trav->next=newnode;
	}
}
int count_nodes()
{
	NODE *trav=start;
	int cnt=0;
	while(trav!=NULL)
	{
		cnt++;
		trav=trav->next;
	}
	return cnt;
}

void insert_at_position(int pos,int data)// try insert at data
{
	NODE *newnode,*trav;
	int p=1;
	if(pos==1)
		add_first(data);
	else if(pos == count_nodes()+1)
		add_last(data);
	else
	{
		newnode=create_node();
		cout<<"new node has been created"<<endl;		
		newnode->data=data;
		cout <<"new node data has been given"<<endl;	
		trav=start;
		cout <<"start assign to trav"<<endl;
		while(p<pos-1)
		{
			cout <<"until 1 less than pos-1"<<endl;
			trav=trav->next;
			cout <<"trav trnsverse to next"<<endl;
			p++;
			cout <<"p increment to pos"<<endl;
		}//traverse till node next to which new node to be attached
		newnode->next=trav->next;
			cout <<"address of trav assigne to address of newnode"<<endl;
		trav->next=newnode;
			cout <<"newnode assign to next to trav"<<endl;
	}
}

void accept_data(int *data)
{
	printf("\n Specify Data");
	scanf("%d",data);
}
int menu_choice()
{
	int choice;
	printf("\n 1. Add Last \
		   \n 2. Add First \
		   \n 3. Add at Position \
		   \n 4. Traverse \
		   \n 5. Reverse \
		   \n 0. Exit");
	scanf("%d",&choice);
	return choice;
}
void traverseList()
{
	NODE *trav=start;
	if(trav==NULL)
	{
		printf("\n List Empty @@@");
		return ;
	}
	while(trav!=NULL)
	{
		printf("%d->",trav->data);
		trav=trav->next;
	}
}

void traverseReverse(NODE *trav)
{
	if(trav==NULL)
		return ;
	traverseReverse(trav->next);
	printf("%d->",trav->data);
}

void reverse_list()
{
	NODE *curr=start,*left=NULL,*right;
	printf("curr->data %d->", curr->data);
	printf("\n");
	
	while(curr!=NULL)
	{
		right=curr->next;
		curr->next=left;
		left=curr;
		curr=right;
//		printf("%d->",right->data);
	}
//	printf("right->data %d->", right->data);
	start=left;
}/*
static void reverse_list() 
{ 
	NODE** start=NULL;
    NODE* prev = NULL; 
    NODE* current = *start; 
    NODE* next = NULL; 
    while (current != NULL) { 
        // Store next 
        next = current->next; 
  
        // Reverse current node's pointer 
        current->next = prev; 
  
        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    *start = prev; 
} 


*/






int main()
{
	int pos,data,choice;
	
	while((choice=menu_choice())!=0)
	{
		switch(choice)
		{
		case 1:
				accept_data(&data);
				add_last(data);
				break;
		case 2:
				accept_data(&data);
				add_first(data);
				break;
		case 3:
				printf("\n Specify Position");
				scanf("%d",&pos);
				if(pos<=0 || pos> count_nodes()+1)
					printf("\n Invalid Position");
				else
				{
					accept_data(&data);
					insert_at_position(pos,data);
				}
				break;
		case 4:
				traverseList();
				printf("\n");
				traverseReverse(start);
				break;
		case 5:
				reverse_list();
				traverseList();
				break;
	
		}
	}

}
