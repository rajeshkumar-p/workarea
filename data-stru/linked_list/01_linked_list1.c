
/****************************************************************************

Linked list sample program using Global variables [Pointer's to Linked List]
* No argument passing in function call
* No return head pointer as well

*****************************************************************************/
#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int value;
	struct node *next;		
}mynode;

// global declarations
mynode *head, *temp, *iter, *prev;

void insert_at_last(int value)
{
	// node creation
	temp = (mynode *) malloc(sizeof(mynode));
	temp->value = value;
	temp->next = NULL;

	if(head == NULL)
	{
		// List is Empty 
		head = temp;
	}	
	else
	{
		// List is non empty
		iter = head;
			
		// iterate over the list upto the end	
		while(iter->next != NULL)
			iter = iter->next;
				
		// now insert the element in the end
		iter->next = temp;
	}			
}	


// for stack implementation we can use this function
void insert_at_first(int value)
{
	// node creation
	temp = (mynode *) malloc(sizeof(mynode));
	temp->value = value;
	temp->next = NULL;

	if(head == NULL)
	{
		// List is Empty 
		head = temp;
	}	
	else
	{
		// List is non empty
		// make newly allocated node next to head
		temp->next = head;

		// make newly allocated node as head
		head = temp;
	}			
}	

// for stack implementation we can use this function
void delete_at_first()
{
	if(head == NULL)
	{
		// List is Empty 
		printf("\n List is Empty \n");
		return;
	}	
	else
	{
		// keep backup of first node
		temp = head; 

		// make newly allocated node next to head
		head = head->next;

		// now free first node
		// TODO for stack implementation return the node value/node 
		free(temp);
	}			
}	

void delete_at_last()
{
	if(head == NULL)
	{
		// List is Empty 
		printf("\n List is Empty \n");
		return;
	}	
	else
	{
		iter = head;
		
		// special case - only one node
		if(iter->next == NULL)
		{
			free(iter);
			head = NULL;	
		}		 

		// traverse upto the end of the list 
		while(iter->next->next != NULL)
			iter = iter->next;

		// now free last node
		free(iter->next);
		iter->next = NULL;
	}			
}	

void delete_node_data(int data)
{
	if(head == NULL)
	{
		// List is Empty 
		printf("\n List is Empty \n");
		return;
	}	
	else
	{
		iter = head;
		prev = head;
		
		// traverse upto the end of the list or the data reach 
		while(iter->value != data && iter->next != NULL)
		{	
			prev = iter;
			iter = iter->next;
		}	

		if(iter->value == data)
		{
			printf("\n Node Present : Node data : %d\n", iter->value);
			if(iter == head)
			{
				// means first node, no previous node
				// head pointer adjustment only
				head = iter->next;
			}		
			else
			{		
				// adjust the pointers
				prev->next = iter->next;
			}

			// now release the node
			free(iter);
		}
		else
		{
			printf("\n Node Not Present ");
		}					
	}			
}	

void display()
{
	printf("\n\n -------------- List --------------- \n");
	if(head == NULL)
	{
		printf("\n List is Empty \n");
		return;	
	}	
	
	iter = head;	

	// iterate over the list upto the end	
	while(iter->next != NULL)
	{
		printf("%d\t", iter->value);
		iter = iter->next;	
	}		
	printf("%d\t", iter->value);
}

int main()
{
printf("\n Hello World \n");

display();
insert_at_last(10);
insert_at_last(20);
insert_at_last(30);
insert_at_last(40);
insert_at_last(50);
display();

insert_at_first(150);
insert_at_first(160);
display();

delete_at_first();
delete_at_first();
display();

delete_at_last();
delete_at_last();
display();

delete_node_data(100);
display();
delete_node_data(200);
display();
delete_node_data(20);
display();
delete_node_data(20);
display();

printf("\n\n Good Bye \n\n");
return 0;
}
