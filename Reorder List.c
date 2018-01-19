/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode* p1,*p2,*p4;
    p1 = head;
    p2 = NULL;
    while (head == NULL||head->next ==NULL)
    {
        return head;
    }
    while (p1)
    {
        struct ListNode* p3 = p1;
        if (p1->next == NULL)
        {
            return head;
        }
        while (p3->next->next)
        {
            p3 = p3->next;
        }
        p4 = p3->next;
        p3->next = NULL;
        p2 = p1->next;
        p1->next = p4;
        p4->next = p2;
        p1 = p2;
    }
    return head;
}
