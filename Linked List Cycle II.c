/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast , *slow;
    fast = head;
    slow = head;
    while (fast&&slow&&fast ->next!= NULL&&fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    if (fast ==NULL || fast ->next ==NULL||fast->next->next ==NULL)
    {
        return NULL;
    }
    if(fast == slow)
    {
        slow = head;
        while (slow != fast)
        {
         slow = slow-> next;
        fast = fast ->next;
        }
    }
       return fast;
}

