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
    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}


int main()
{
    ListNode * head = NULL;
    for(int i=1; i <5; i++)
    {
        append(&head, i);
    }


    show(head);


}



























