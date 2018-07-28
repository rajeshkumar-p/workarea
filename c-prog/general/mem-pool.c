#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MEMORY_POOL_NODES 10

/* Node */
typedef struct node
{
    int    data;
    int    nodeAllocated;
}NODE;

typedef struct Memorypool
{
    NODE       *array[MAX_MEMORY_POOL_NODES];
    int        nodeCounter;
}MEMORYPOOL;

MEMORYPOOL allocNode;

/*
 * initialiseMemoryPool()
 */
void initialiseMemoryPool()
{
   unsigned char uIndx;
   
   /* Initialise the Memory for the Nodes */      
   for(uIndx = 0; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
   {
      allocNode.array[uIndx]= (NODE *)malloc(sizeof(NODE));
      allocNode.array[uIndx]->nodeAllocated = 0;

      allocNode.nodeCounter++;
   }
}

NODE *getTheFreeNodeFromPool()
{
  int uIndx;
  
   /* Get the Memory from the Pool of Nodes */
   for(uIndx = 0; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
   {
      if(allocNode.array[uIndx]->nodeAllocated == 0) 
      {
          allocNode.array[uIndx]->nodeAllocated = 1;
          allocNode.nodeCounter--; 
          break;
      }
   }  

  if(uIndx == MAX_MEMORY_POOL_NODES) 
  {
     printf(" No Free Nodes are available \n");
     return NULL;
  }
  return allocNode.array[uIndx];
}

/* 
 *  Add the Node to Memory pool
 */
void addTheNodeToMemoryPool(unsigned char uIndx)
{
   /* Add the Node to Pool */
   if(allocNode.array[uIndx]->nodeAllocated == 1 )
   {
         allocNode.array[uIndx]->data = 0;
         allocNode.array[uIndx]->nodeAllocated = 0; 
         allocNode.nodeCounter++;
    }
   else
   {
      printf("No Nodes are there Add \n");
      return;
   }
}

/*
 * deallocateTheMemoryPool-  Deallocate the Memory Pool
 */
void deallocateTheMemoryPool(void)
{
  unsigned char uIndx;

  /* De-allocate the Memory Pool */
  for(uIndx = 0; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
    {
        free(allocNode.array[uIndx]);
    }
}
              
/* Main */
int main()
{
    unsigned char uIndx, index;
   
   // Step 1:
   /* Initialise the Memory Pool */
   initialiseMemoryPool();

   // Step 2:
   /* Get the Node from the Memory Pool */
   for(uIndx=0 ; uIndx< MAX_MEMORY_POOL_NODES; uIndx++)
   { 
      NODE *node= NULL; 
      int data;
      
      node = getTheFreeNodeFromPool();

      if(node)
      {
          printf("Enter the Data to be added in the Linklist \n");
          scanf("%d", &data);
    
          node->data = data;
      }
   }
  
   /* Display the Data */
   printf(" Display Data \n");
   for (uIndx=0 ; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
    {
      printf("%d\n", allocNode.array[uIndx]->data);
    }

   
   //Step 3:
   /* Add the Node to Memory Pool */   
   printf(" Enter the Node to be added to memory pool \n");
   scanf("%d", &index);
   
   addTheNodeToMemoryPool(index);

   /* Display the Data */
   printf(" Display Data after adding Node to Free Pool \n");
   for (uIndx=0 ; uIndx<MAX_MEMORY_POOL_NODES; uIndx++)
    {
      printf("%d\n", allocNode.array[uIndx]->data);
    }

   //Step 4:
   /* De Allocate the Memory Pool */
   deallocateTheMemoryPool();
   return 0;
}


