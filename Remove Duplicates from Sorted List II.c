/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* newp = (struct ListNode*)malloc(sizeof(struct ListNode));
    newp ->next = NULL;
    newp -> val =NULL;
    struct ListNode* newa = newp;
    struct ListNode* newn = head;
    while (head == NULL)
    {
        return head;
    }
    while (newn !=NULL)
    {
        int m = 0;
        struct ListNode* newm = head;
        int s = newn->val;
        while (newm != NULL)
        {
            if (newm->val == s)
            {
                m++;
            }
            newm = newm-> next;
        }
        if (m == 1)
        {
            struct ListNode* newq = (struct ListNode*)malloc(sizeof(struct ListNode));
            newa -> next = newq;
            newq -> val = s;
            newq -> next = NULL;
            newa = newq;
        }
        newn = newn-> next;
    }
    return newp->next;
}


// 创建一个新的链表，然后遍历旧列表，如果该点的值在整个旧列表的中只出现过一次，则将其加入新链表 最后返回新链表
