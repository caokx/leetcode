#ifndef STRUCT_NODES
#define STRUCT_NODES
#include<stdio.h>
#include<malloc.h>
//二叉树节点
struct TreeNode
{ 
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};
//链表节点
struct ListNode
{
	struct TreeNode * treeNode;
	struct ListNode* next;
};
//栈
struct Stack
{
	struct ListNode* header;
	void (*push)(struct Stack* stackPtr, struct TreeNode* node);
	struct TreeNode* (*pop)(struct Stack* stackPtr); 
};
//队列
struct Queue
{
	struct ListNode* front;
	struct ListNode* rear;
	void (*add)(struct Queue* queuePtr, struct TreeNode* node);
	struct TreeNode* (*del)(struct Queue* queuePtr); 
};
#endif



