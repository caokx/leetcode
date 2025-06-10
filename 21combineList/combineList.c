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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    if((list1==NULL) && (list2==NULL))
    {
        return NULL;
    }
    else if(list1==NULL)
    {
       return list2;
    }
    else if(list2==NULL)
    {
        return list1;
    }

    struct ListNode* head;
    struct ListNode* tail;
    if(list1->val <= list2->val)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
    }
    tail = head;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val <= list2->val)
        {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
    }

    if(list1 == NULL)
    {
        tail->next = list2;
    }
    else if(list2 == NULL)
    {
        tail->next = list1;
    }

    return head;


}


int main()
{
    ListNode * list1 = NULL;
    ListNode * list2 = NULL;
    append(&list1, 1);
    append(&list1, 2);
    append(&list1, 4);
    append(&list2, 1);
    append(&list2, 3);
    append(&list2, 4);
    show(list1);
    show(list2);
    show(mergeTwoLists(list1, list2));
}



























