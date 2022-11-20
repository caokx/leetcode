#include "nodes.h"

void push(struct Stack* stackPtr, struct TreeNode* treeNode);
struct TreeNode* pop(struct Stack* stackPtr); 
//创建堆栈
struct Stack* createStack()
{
	struct Stack* stackPtr = (struct Stack*)malloc(sizeof(struct Stack));
	stackPtr->header = NULL;
	stackPtr->pop = pop;
	stackPtr->push = push;
	return stackPtr;
}
//入栈
void push(struct Stack* stackPtr, struct TreeNode* treeNode)
{
	struct ListNode* listNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	listNode->treeNode = treeNode;
	listNode->next = stackPtr->header;
	stackPtr->header = listNode;
	return;
}
//出栈
struct TreeNode* pop(struct Stack* stackPtr)
{
	if(stackPtr->header == NULL)
	{
		printf("stack is empty \n");
		return NULL;
	}

	struct ListNode* listNode = stackPtr->header;
	struct TreeNode* treeNode =  listNode->treeNode;
	stackPtr->header = listNode->next;
	free(listNode);
	return treeNode;
}


//创建二叉树
struct TreeNode* createBinaryTree(int array[], int n, int index)
{
	if (array[index] == -1)
	{
		return NULL;
	}
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->data = array[index];
	if (index * 2 + 1 < n)
	{
		root->left = createBinaryTree(array, n, 2 * index + 1);
	}
	else
	{
		root -> left =  NULL;
	}
	if (index * 2 + 2 < n)
	{
		root->right = createBinaryTree(array, n, 2 * index + 2);
	}
	else
	{
		root->right =  NULL;
	}
	return root;
}
//二叉树中序遍历
void inorderTraversal(struct TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	inorderTraversal(root->left);
	printf("%d\t", root->data);
	inorderTraversal(root->right);
}
//二叉树的非递归中序遍历
void inorderTraversal_(struct TreeNode* root)
{
	struct Stack* stackPtr = createStack(); //开辟栈
	struct TreeNode* T = root;

	while(T || stackPtr->header)
	{
		while(T)
		{
			stackPtr->push(stackPtr, T);
			T = T->left;
		}
		if(stackPtr->header)
		{
			T = stackPtr->pop(stackPtr);
			printf("%d\t", T->data);
			T = T->right;
		}

	}
	// struct TreeNode* treeNode = stackPtr->pop(stackPtr);
	// printf("%d", treeNode->data);
}
//二叉树的先序遍历
void preorderTraversal(struct TreeNode* root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d\t", root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
//二叉树的非递归先序遍历
void preorderTraversal_(struct TreeNode* root)
{
	struct Stack* stackPtr = createStack(); //开辟栈
	struct TreeNode* T = root;
	while(T || stackPtr->header)
	{
		while(T)
		{
			printf("%d\t", T->data);
			stackPtr->push(stackPtr, T);
			T = T->left;
		}
		if(stackPtr->header)
		{
			T = stackPtr->pop(stackPtr);
			T = T->right;
		}




	}
}
//后序遍历
void postorderTraversal(struct TreeNode* root)
{
	if(root == NULL)
	{
		return;
	}
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d\t", root->data);
}
//非递归后序遍历
void postorderTraversal_(struct TreeNode* root)
{
	struct Stack* stackPtr = createStack(); //开辟栈

	struct TreeNode* T = NULL;
	struct TreeNode* preT = NULL;

	stackPtr->push(stackPtr, root);
	while(stackPtr->header)
	{	
		T = stackPtr->pop(stackPtr);
		//判断T是叶子节点，或者T的左右子树被访问
		if((T->left == NULL && T->right == NULL)||(preT!=NULL && (preT == T->left || preT == T->right)))
		{
			printf("%d\t", T->data);
			preT = T;
		}
		else
		{
			stackPtr->push(stackPtr, T);
			if(T->right)
			{
				stackPtr->push(stackPtr, T->right);
			}
			if(T->left)
			{
				stackPtr->push(stackPtr, T->left);
			}
		}
	}
}

void test01()
{
	int array[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, -1, -1, -1, 6 };
	struct TreeNode* tree = createBinaryTree(array, sizeof(array) / sizeof(int), 0);
	postorderTraversal(tree);
	printf("test stack .......\n");
	postorderTraversal_(tree);
}









int main() {
	test01();






	system("pause");
	return 0;
}

