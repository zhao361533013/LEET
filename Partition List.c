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
    struct ListNode*a_1 = malloc (sizeof(struct ListNode));
    struct ListNode*a_2 = malloc (sizeof(struct ListNode));
    struct ListNode* a = a_1;
    struct ListNode* m = a_2;
    
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
    a -> next = a_2->next;
    return a_1->next;
}
