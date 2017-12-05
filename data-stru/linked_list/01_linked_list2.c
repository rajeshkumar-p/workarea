/****************************************************************************

Linked list sample program using Global variables [Pointer's to Linked List]
* No argument passing in function call


*****************************************************************************/
#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int value;
	struct node *next;		
}mynode;

// global declarations

mynode* insert_at_last(mynode *head, int value)
{
    mynode *temp, *iter;
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
	
	return head;	
}	


// for stack implementation we can use this function
mynode* insert_at_first(mynode *head, int value)
{
    mynode *temp;
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
	return head;	
}	

// for stack implementation we can use this function
mynode* delete_at_first(mynode *head)
{
    mynode *temp;
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
	return head;	
}	

mynode* delete_at_last(mynode *head)
{
    mynode *temp, *iter;
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
	return head;	
}	

mynode* delete_node_data(mynode *head, int data)
{
    mynode *temp, *iter, *prev;
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
	return head;	
}	

void display(mynode *head)
{
    mynode *temp, *iter;
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
mynode *head = NULL;	

display(head);
head = insert_at_last(head, 10);
head = insert_at_last(head, 20);
head = insert_at_last(head, 30);
head = insert_at_last(head, 40);
head = insert_at_last(head, 50);
display(head);

head = insert_at_first(head, 150);
head = insert_at_first(head, 160);
display(head);

head = delete_at_first(head);
head = delete_at_first(head);
display(head);

head = delete_at_last(head);
head = delete_at_last(head);
display(head);

head = delete_node_data(head, 100);
display(head);
head = delete_node_data(head, 200);
display(head);
head = delete_node_data(head, 20);
display(head);
head = delete_node_data(head, 20);
display(head);

printf("\n\n Good Bye \n\n");
return 0;
}
