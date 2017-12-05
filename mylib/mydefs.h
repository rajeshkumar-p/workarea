#ifndef _MYDEF_H
#define _MYDEF_H

#define TRUE  1
#define FALSE 0

#define GREEN	0	
#define YELLOW	1
#define RED		2

#define YES 1
#define NO  0

#define DEBUG 1

// node definition
typedef struct node1
{
	int value;
	struct node *next;		
}mynode1;

typedef struct node
{
	int data;
	struct node *next;		
}mynode;

#endif // _MYDEF_H
//
