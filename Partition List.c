/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
     if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode r,w;
    struct ListNode* a = &r;
    struct ListNode* m = &w;
    
    while (head)
    {
        if (head->val < x)
        {
            a->next = head;
            a = head;
            head = head->next;
        }
        else 
        {
            m->next = head;
            m = head;
            head = head->next;
        }
    }
    m -> next = NULL;
    a -> next = w.next;
    return r.next;
}
