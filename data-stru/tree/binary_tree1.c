/******************************************************************
- An Ordered Tree is one in which the children of each node are ordered.
- Binary tree is an ordered tree with all nodes having at most 2 childrens.

Recursive Definition : A Binary tree is either a
- Leaf or
- An internal node (the root) and one/two binary trees
  (left subtree and/or right subtree)

Examples of a Binary Tree : 
1) Arithmetic Expressions  
2) Decision Trees

*******************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
};

int rightmost_data(struct node *temp);
void destroy_tree(struct node *temp);
int minimum_value(struct node *temp);
int maximum_value(struct node *temp);
void display(struct node *temp);

struct node *insertion(struct node *temp,int data)
{
	if(temp!=NULL)
	{
		if(data > temp->data)
			temp->rlink = insertion(temp->rlink,data);
		else
			temp->llink = insertion(temp->llink,data);
	}
	else
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = data;
		temp->llink = NULL;
		temp->rlink = NULL;
		return temp;
	}
	return temp;
}

struct node *deletion(struct node *temp,int data)
{
	struct node *ip;
	if(temp!=NULL)
	{
		if(data == temp->data)
		{
			// Scenario 1 : No Child
			// If It Has No Child
			if(temp->llink == NULL && temp->rlink == NULL)
			{
				printf("\nDeleted value is %d\n",temp->data);
				free(temp);
				temp = NULL;
				return temp;
			}

			// Scenario 2 : Only one Child
			// If It Has Only Left Child
			if(temp->rlink == NULL && temp->llink->rlink == NULL && temp->llink->llink == NULL)
			{
				temp->data = temp->llink->data;
				free(temp->llink);
				temp->llink = NULL;
				return temp;
			}
			// If It Has Only Right Child
			if(temp->llink == NULL && temp->rlink->llink == NULL && temp->rlink->rlink == NULL)
			{
				temp->data = temp->rlink->data;
				free(temp->rlink);
				temp->rlink = NULL;
				return temp;
			}

			// FIXME Scenario 3 : Two Child - Move Predecessor
			// If It Has Two Child ( Left Child Right Most )
			if(temp->llink->rlink != NULL)
			{
				temp->data = rightmost_data(temp->llink);
				return temp;
			}
			// If It Left Child & No Right Child
			if(temp->llink->rlink == NULL)
			{
				ip = temp->llink;
				free(temp);
				ip->rlink = temp->rlink;
				return ip;
			}
		}
		else if(data > temp->data)
			temp->rlink = deletion(temp->rlink,data);
		else if(data < temp->data)
			temp->llink = deletion(temp->llink,data);
	}
	else
		printf("\nTree Is Empty");
	return temp;
}

int rightmost_data(struct node *temp)
{
	struct node *ip,*ip1;
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
	struct node *head,*ip;
	head = NULL;

	// sample tree construction
	head = insertion(head,10);
	head = insertion(head,5);
	head = insertion(head,15);
	head = insertion(head,3);
	head = insertion(head,7);
	head = insertion(head,12);
	head = insertion(head,18);
	head = insertion(head,1);
	head = insertion(head,4);
	head = insertion(head,6);
	head = insertion(head,17);
	head = insertion(head,20);

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
				head = insertion(head,data);
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
					head = deletion(head,data);
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
void display(struct node *temp)
{
	if(temp!=NULL)
	{
		display(temp->llink);
		printf("%d\t",temp->data);
		display(temp->rlink);
	}
}

int minimum_value(struct node *temp)
{
	while(temp->llink != NULL)
		temp = temp->llink;

	return (temp->data);	
}

int maximum_value(struct node *temp)
{
	while(temp->rlink != NULL)
		temp = temp->rlink;

	return (temp->data);	
}

// use post order traversal to destroy tree
void destroy_tree(struct node *temp)
{
	if(temp!=NULL)
	{
		destroy_tree(temp->llink);
		destroy_tree(temp->rlink);
		free(temp);
	}
}


