/****************************************************************************

Linked list sample program using Global variables [Pointer's to Linked List]
* Pass address of head pointer
* No need to return head pointer to the calling function 

*****************************************************************************/
#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int value;
	struct node *next;		
}mynode;

void insert_at_last(mynode **head, int value)
{
	mynode *iter, *temp;

	// node creation
	temp = (mynode *) malloc(sizeof(mynode));
	temp->value = value;
	temp->next = NULL;

	if(*head == NULL)
	{
		// List is Empty 
		*head = temp;
	}	
	else
	{
		// List is non empty
		iter = *head;
			
		// iterate over the list upto the end	
		while(iter->next != NULL)
			iter = iter->next;
				
		// now insert the element in the end
		iter->next = temp;
	}			
}	

// for stack implementation we can use this function
void insert_at_first(mynode **head, int value)
{
	mynode *temp;
	// node creation
	temp = (mynode *) malloc(sizeof(mynode));
	temp->value = value;
	temp->next = NULL;

	if(*head == NULL)
	{
		// List is Empty 
		*head = temp;
	}	
	else
	{
		// List is non empty
		// make newly allocated node next to head
		temp->next = *head;

		// make newly allocated node as head
		*head = temp;
	}			
}	

// for stack implementation we can use this function
void delete_at_first(mynode **head)
{
	mynode *temp;

	if(*head == NULL)
	{
		// List is Empty 
		printf("\n List is Empty \n");
		return;
	}	
	else
	{
		// keep backup of first node
		temp = *head; 

		// make newly allocated node next to head
		*head = (*head)->next;

		// now free first node
		// TODO for stack implementation return the node value/node 
		free(temp);
	}			
}	

void delete_at_last(mynode **head)
{
	mynode *iter;

	if(*head == NULL)
	{
		// List is Empty 
		printf("\n List is Empty \n");
		return;
	}	
	else
	{
		iter = *head;
		
		// special case - only one node
		if(iter->next == NULL)
		{
			free(iter);
			*head = NULL;	
		}		 

		// traverse upto the end of the list 
		while(iter->next->next != NULL)
			iter = iter->next;

		// now free last node
		free(iter->next);
		iter->next = NULL;
	}			
}	

void delete_node_data(mynode **head, int data)
{
	mynode *iter, *prev;

	if(*head == NULL)
	{
		// List is Empty 
		printf("\n List is Empty \n");
		return;
	}	
	else
	{
		iter = *head;
		prev = *head;
		
		// traverse upto the end of the list or the data reach 
		while(iter->value != data && iter->next != NULL)
		{	
			prev = iter;
			iter = iter->next;
		}	

		if(iter->value == data)
		{
			printf("\n Node Present : Node data : %d\n", iter->value);
			if(iter == *head)
			{
				// means first node, no previous node
				// head pointer adjustment only
				*head = iter->next;
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

void display(mynode **head)
{
	mynode *iter;

	printf("\n\n -------------- List --------------- \n");
	if(*head == NULL)
	{
		printf("\n List is Empty \n");
		return;	
	}	
	
	iter = *head;	

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
mynode *head = NULL;
	
printf("\n Hello World \n");

display(&head);
insert_at_last(&head, 10);
insert_at_last(&head, 20);
insert_at_last(&head, 30);
insert_at_last(&head, 40);
insert_at_last(&head, 50);
display(&head);

insert_at_first(&head, 150);
insert_at_first(&head, 160);
display(&head);

delete_at_first(&head);
delete_at_first(&head);
display(&head);

delete_at_last(&head);
delete_at_last(&head);
display(&head);

delete_node_data(&head, 100);
display(&head);
delete_node_data(&head, 200);
display(&head);
delete_node_data(&head, 20);
display(&head);
delete_node_data(&head, 20);
display(&head);

printf("\n\n Good Bye \n\n");
return 0;
}
