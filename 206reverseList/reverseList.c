#include"nodes.h"

//末尾插入节点
void append(ListNode** head, int val)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if ((*head) == NULL) {
        (*head) = newNode;  // 如果链表为空，直接作为头节点
        return;
    }

    ListNode* current = *head;
    while (current->next != NULL) {  // 找到最后一个节点（非NULL）
        current = current->next;
    }
    current->next = newNode;  // 连接新节点
}
//显示整条链表
void show(ListNode* head)
{
    ListNode* tmp = head;
    while(tmp != NULL)
    {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

//反转链表
ListNode* reverseList(ListNode* head) 
{
    if(head == NULL)
    {
        return NULL;
    }
    //创建临时指针
    ListNode* post;
    ListNode* tmp;

    if(head->next == NULL)
    {
        return head;
    }
    else
    {
        post = head->next;
        head->next = NULL;
    }

    while(post)
    {
       
            tmp = post->next;
            post->next = head;
            head = post;
            post = tmp;
    }
    return head;
}
int main()
{
    ListNode * head = NULL;
    for(int i=1; i <5; i++)
    {
        append(&head, i);
    }
    show(head);
    head = reverseList(head);
    printf("a\n");
    show(head);
}



























