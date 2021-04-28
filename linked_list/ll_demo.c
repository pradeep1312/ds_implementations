#include <stdio.h>
#include <stdlib.h>

typedef struct node
{	
	int val;
	struct node* next; 
}node_t;

node_t* head;

node_t* insert_node_at_start(int value);
void traverse_ll();
node_t* traverse_and_find(int value);
void insert_after_fix_node(node_t* pre_node,node_t* node_to_insert);

int main()
{
	
	head=NULL;
	node_t* temp;
	for(int i=0;i<10;i++)
	{
		temp=insert_node_at_start(i);
		temp->next=head;
		head=temp;
	}
	traverse_ll();
	node_t* pre_node=traverse_and_find(5);
	temp=insert_node_at_start(20);
	insert_after_fix_node(pre_node,temp);
	traverse_ll();
	return 0;
}

//inserting node at start of linked list
node_t* insert_node_at_start(int value)
{
	node_t* n;
	n=malloc(sizeof(node_t));
	n->val=value;
	return n;
}

//method to traverse through linked list
void traverse_ll()
{
	node_t* n;
	n=head;
	printf("Values of linked list are as follows-\n");
	while(n!=NULL)
	{
		printf("%d -",n->val);
		n=n->next;
	}
	printf("\n");
}


//method to find certain element in linked list
node_t* traverse_and_find(int value)
{
	node_t* n=head;
	while(n!=NULL)
	{
		if(n->val==value)
		{
			printf("value %d exists in ll\n",n->val);
			return n;
		}
		n=n->next;
	}
}


//method to insert node after certain node 
void insert_after_fix_node(node_t* pre_node,node_t* node_to_insert)
{
	node_to_insert->next=pre_node->next;
	pre_node->next=node_to_insert;
}