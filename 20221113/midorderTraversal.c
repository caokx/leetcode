#include<stdio.h>
#include<malloc.h>


struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct ListNode
{
	struct TreeNode* treeNode;
	struct ListNode* next;
};


struct Stack
{
	struct ListNode* header;
	void (*push)(struct ListNode* header);
	int (*pop)(struct ListNode* header);
};







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



void test01()
{
	int array[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, -1, -1, -1, 6 };
	struct TreeNode* tree = createBinaryTree(array, sizeof(array) / sizeof(int), 0);
	inorderTraversal(tree);
}









int main() {
	test01();






	system("pause");
	return 0;
}

