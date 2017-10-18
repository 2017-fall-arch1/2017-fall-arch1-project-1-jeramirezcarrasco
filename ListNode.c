#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListNode.h"
//this is where the structure of the "class" is made
struct ListNode
{
  char *EmpName;
  struct ListNode *Left;
  struct ListNode *Right;
};
//creating the "class"
struct ListNode *Create(char *EmpNames)
{
  struct ListNode *Node = (struct ListNode *)malloc(sizeof(struct ListNode));
  Node ->EmpName = EmpNames;
  Node ->Left=NULL;
  Node ->Right=NULL;
  return Node;
}
//Method for cleaning the entire tree
struct ListNode *Clean(struct ListNode *Node)
{
  Empty(Node);
  Node = NULL;
  free(Node);
  return Node;
}
//Method goes trough the entire tree and deletes every node
void Empty (struct ListNode *Node)
{
  if(Node == NULL)
    return;
  Empty(Node->Left);
  Empty(Node->Right);
  free(Node->EmpName);
  free(Node);
}
//Method of adding a new node to the tree
struct ListNode *Add(struct ListNode *node,char *Name)
{
  int lenghts;
  char *InputName;
  struct ListNode *i;
  //this part of for deciding the size of the Employee
  for(lenghts = 0;Name[lenghts];lenghts++)
    ;
  InputName = (char *)malloc(lenghts+1);
  for(lenghts = 0;Name[lenghts]; lenghts++)
    InputName[lenghts] = Name[lenghts];
  InputName[lenghts] = 0;
  if(node == NULL)
    return Create(InputName);
  //using strcmp it checks if the node fields are bigger or smaller
  int Difference = strcmp(node->EmpName,InputName);
  if(Difference==0)
    {
      printf("Employee name already in the list");
      return node;
    }
  else if(Difference>0)
    {
      node->Left = Add(node->Left, InputName);
    }
  else
    {
      node->Right = Add(node->Right, InputName);
    }
  return node;
}
//method for printing the tree node by traversing the tree
void print(struct ListNode *Node)
{
  struct ListNode *i=Node;
  if(i !=NULL)
    {
      print(i->Left);
      printf("%s\n", i->EmpName);
      print(i->Right);
    }
}
//method for deleting a single name in the node
struct ListNode *DeleteName(struct ListNode *Node,char *Name)
{
  if(Node == NULL)
    return Node;
  if(Name == NULL)
    return Node;
  char * X = Name;
  X[strcspn(X, "\n")] = 0;
  char * Y = Node->EmpName;
  Y[strcspn(Y, "\n")] = 0;
  //this is for checking if name that wants to be deleted is found
  if(strcmp(Name,Node->EmpName)==-1)
    Node->Left=DeleteName(Node->Left,Name);
  else if(strcmp(Name,Node->EmpName)==1)
    Node->Right = DeleteName(Node->Right,Name);
  else
    {
      if(Node->Left==NULL)
	{
	  struct ListNode *Jump = Node->Right;
	  free(Node);
	  return Jump;
	}
      else if(Node->Right ==NULL)
	{
	  struct ListNode *Jump = Node->Left;
	  free(Node);
	  return Jump;
	}
      struct ListNode *Jump =Node ->Right;
      while(Jump->Left !=NULL)
	Jump = Jump ->Left;
      // in case the root has 2 childrens it change from the root with the possible lowest right node
      Node->EmpName = Jump ->EmpName;
      Node->Right = DeleteName(Node->Right,Jump->EmpName);
    }
  return Node;
}
//printing the text files
void printfile(struct ListNode *Node,FILE *UserFile)
{
  struct ListNode *i=Node;
  if(i !=NULL)
    {
      printfile(i->Left,UserFile);
      fprintf(UserFile,"%s\n",i->EmpName);
      printfile(i->Right,UserFile);
    }
}
