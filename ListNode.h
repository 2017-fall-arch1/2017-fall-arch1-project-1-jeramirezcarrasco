#ifndef UNTITLED_LISTNODE_H
#define UNTITLED_LISTNODE_H
struct ListNode;
struct ListNode *Clean(struct ListNode *Node);
void Empty (struct ListNode *Node);
struct ListNode *Create(char *EmpNames);
struct ListNode *Add(struct ListNode *Node,char *Name);
void print(struct ListNode *Node);
void printfile(struct ListNode *Node,FILE *UserFile);
struct ListNode *DeleteName(struct ListNode *Node,char *Name);
#endif






