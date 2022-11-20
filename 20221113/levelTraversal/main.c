#include "nodes.h"

//对列入队函数
void add(struct Queue* queuePtr, struct TreeNode* treeNode)
{
    //创建队列结点
    struct ListNode* listNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    listNode->treeNode = treeNode;
    listNode->next = NULL;
    //将结点插入队列
    if(queuePtr->front == NULL)
    {
        queuePtr->front = listNode;
        queuePtr->rear = listNode;
    }
    else
    {
        queuePtr->rear->next = listNode;
        queuePtr->rear = listNode;
    }
    return;
}

//对列出队函数
struct TreeNode* del(struct Queue* queuePtr)
{
    if(queuePtr->front==NULL)
    {
        return NULL;
    }
    else if(queuePtr->front == queuePtr->rear)
    {
        struct TreeNode* temp = queuePtr->front->treeNode;
        free(queuePtr->front);
        queuePtr->front = NULL;
        queuePtr->rear = NULL;
        return temp;
    }
    else
    {
        struct TreeNode* temp = queuePtr->front->treeNode;
        struct ListNode* temp_ = queuePtr->front;
        queuePtr->front = queuePtr->front->next;
        free(temp_);
        return temp;
    }
}
//创建队列
struct Queue* createQueue()
{
    struct Queue* queuePtr = (struct Queue*)malloc(sizeof(struct Queue));
    queuePtr->front = NULL;
    queuePtr->rear = NULL;
    queuePtr->add = add;
    queuePtr->del = del;
    return queuePtr;
}
//创建二叉树
struct TreeNode * createBinaryTree(int array[], int n, int index)
{
    if(array[index] == -1)
    {
        return NULL;
    }
    struct TreeNode * treeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    treeNode ->data = array[index];

    if(2*index+1 < n)
    {
        treeNode->left = createBinaryTree(array, n, 2*index+1);
    }
    else
    {
        treeNode->left = NULL;
    }

    if(2*index+2 < n)
    {
        treeNode->right = createBinaryTree(array, n, 2*index+2);
    }
    else
    {
        treeNode->right = NULL;
    }
    return treeNode;
}
//先序遍历
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
//层次遍历
void levelTraversal(struct TreeNode* root)
{
    struct Queue * queuePtr = createQueue();
    queuePtr->add(queuePtr, root);
    struct TreeNode * T;
    while(queuePtr->front)
    {
        T = queuePtr->del(queuePtr);
        printf("%d\t", T->data);
        if(T->left)
        {
            queuePtr->add(queuePtr, T->left);
        }
        if(T->right)
        {
            queuePtr->add(queuePtr, T->right);
        }
    }


}

void test01()
{
	int array[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, -1, -1, -1, 6 };
	struct TreeNode* root = createBinaryTree(array, sizeof(array) / sizeof(int), 0);
	// preorderTraversal(tree);
    levelTraversal(root);
}

int main()
{
    test01();
    return 0;
}