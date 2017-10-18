#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListNode.h"

int gets_n(char *s,int limit)
{
  char *p = s;
  char c;
  if(fgets(s, limit, stdin))
    {
      while((c = *p) && c != '\n')
	p++;
      if(c == '\n')
	*p=0;
    }
  return (p-s);
}

void main()
{
  struct ListNode *Node = NULL;
  printf("Add employees with keyboard \n");
  char Tmp[100];
  while(gets_n(Tmp, 100))
    Node = Add(Node,Tmp);
  printf("----------------------------------------------\n");
  printf("Printing database\n");
  printf("List contents, after building list:\n");
  print(Node);
  printf("------------------------------------------------\n");
  printf("Add specific name to delete\n");
  char UserInput[100];
  fgets(UserInput,100,stdin);
  Node = DeleteName(Node,UserInput);
  printf("------------------------------------------------\n");
  printf("Printing database\n");
  printf("List contents, after name deleted\n");
  print(Node);
  printf("-------------------------------------------------\n");
  printf("Adding names from file\n");
  FILE *UserFile = fopen("Test1.txt", "r");
  if(UserFile == NULL)
    {
      printf("Couldn't open file\n");
      exit(1);
    }
  while(fgets(Tmp, sizeof(Tmp),UserFile))
    {
      Tmp[strcspn(Tmp, "\n")] = 0;
      Node = Add(Node,Tmp);
    }
  fclose(UserFile);
  FILE *OutputFile = fopen("Test2.txt","w");
  printf("Printing names to file\n");
  printfile(Node,OutputFile);
  printf("Last List print\n");
  print(Node);
  printf("Deleting the entire database\n");
  Node = Clean(Node);
  printf("Printing deleted list\n");
  print(Node);
}
