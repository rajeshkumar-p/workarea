#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}mynode;

int rightmost_data(mynode *temp);
int minimum_value(mynode *temp);
int maximum_value(mynode *temp);

void display(mynode *temp);
void destroy_tree(mynode *temp);

void insertion(mynode **temp, int data)
{
	if(*temp != NULL)
	{
		if(data > (*temp)->data)
			insertion(&(*temp)->rlink,data);
		else
			insertion(&(*temp)->llink,data);
	}
	else
	{
		*temp = (mynode *)malloc(sizeof(mynode));
		(*temp)->data = data;
		(*temp)->llink = NULL;
		(*temp)->rlink = NULL;
	}
	return ;
}

void *deletion(mynode **temp,int data)
{
	mynode *ip;

	if(*temp != NULL)
	{
		if(data == (*temp)->data)
		{
			// Scenario 1 : No Child
			// If It Has No Child
			if((*temp)->llink == NULL && (*temp)->rlink == NULL)
			{
				printf("\nDeleted value is %d\n",(*temp)->data);
				free(*temp);
				*temp = NULL;
				return;
			}

			// Scenario 2 : Only one Child
			// If It Has Only Left Child
			if((*temp)->rlink == NULL && (*temp)->llink->rlink == NULL &&
				(*temp)->llink->llink == NULL)
			{
				(*temp)->data = (*temp)->llink->data;
				free((*temp)->llink);
				(*temp)->llink = NULL;
				return;
			}
			// If It Has Only Right Child
			if((*temp)->llink == NULL && (*temp)->rlink->llink == NULL &&
				(*temp)->rlink->rlink == NULL)
			{
				(*temp)->data = (*temp)->rlink->data;
				free((*temp)->rlink);
				(*temp)->rlink = NULL;
				return ;
			}

			// FIXME Scenario 3 : Two Child - Move Predecessor
			// If It Has Two Child ( Left Child Right Most )
			if((*temp)->llink->rlink != NULL)
			{
				(*temp)->data = rightmost_data((*temp)->llink);
				return;
			}
			// If It Left Child & No Right Child
			if((*temp)->llink->rlink == NULL)
			{
				ip = (*temp)->llink;
				free(*temp);
				ip->rlink = (*temp)->rlink;
				*temp = ip;
				return;
				//return ip;
			}
		}
		else if(data > (*temp)->data)
			deletion(&(*temp)->rlink,data);
		else if(data < (*temp)->data)
			deletion(&(*temp)->llink,data);
	}
	else
		printf("\nTree Is Empty");
	return ;
}

int rightmost_data(mynode *temp)
{
	mynode *ip,*ip1;
	int data;
	ip = temp;
	while(ip->rlink!=NULL)
	{
		ip1 = ip;
		ip = ip->rlink;
	}
	data = ip->data;
	free(ip);
	ip1->rlink = NULL;
	return data;
}

void main()
{
	int choice,data;
	mynode *head,*ip;

	head = NULL;

	// sample tree construction
	insertion(&head,10);
	insertion(&head,5);
	insertion(&head,15);
	insertion(&head,3);
	insertion(&head,7);
	insertion(&head,12);
	insertion(&head,18);
	insertion(&head,1);
	insertion(&head,4);
	insertion(&head,6);
	insertion(&head,17);
	insertion(&head,20);

	do
	{
		printf("\n1.Node Insertion");
		printf("\n2.Node Deletion");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter The Value To Insert: ");
				scanf("%d",&data);
				insertion(&head,data);
			break;
			case 2:
				printf("\nEnter The Node Value To Be Deleted : ");
				scanf("%d",&data);
				// Node to be deleted is head node and it has no left child
				if(head->data == data && head->llink == NULL)
				{
					ip = head;
					head = head->rlink;
					free(ip);
				}
				// Node to be deleted is head node and it has no right child
				else if(head->data == data && head->rlink == NULL)
				{
					ip = head;
					head = head->llink;
					free(ip);
				}
				else
				{
					deletion(&head,data);
				}
			break;
			case 3:
				printf("\nTree\n");
				if(head == NULL)
				{
					printf("\nTree is empty");
					break;
				}
					display(head);
			break;
		}
	}while(choice > 0 && choice < 4);

	destroy_tree(head);
	printf("\n Tree Destroyed \n");
}

// inorder traversal print binary search tree
// in ascending order
void display(mynode *temp)
{
	if(temp!=NULL)
	{
		display(temp->llink);
		printf("%d\t",temp->data);
		display(temp->rlink);
	}
}

int minimum_value(mynode *temp)
{
	while(temp->llink != NULL)
		temp = temp->llink;

	return (temp->data);	
}

int maximum_value(mynode *temp)
{
	while(temp->rlink != NULL)
		temp = temp->rlink;

	return (temp->data);	
}

// use post order traversal to destroy tree
void destroy_tree(mynode *temp)
{
	if(temp!=NULL)
	{
		destroy_tree(temp->llink);
		destroy_tree(temp->rlink);
		free(temp);
	}
}


