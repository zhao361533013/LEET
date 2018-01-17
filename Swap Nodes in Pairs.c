/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL||head->next == NULL)
    {
        return head;
    }
    else 
    {
        struct ListNode* n ;
        struct ListNode* m;
        m = head->next;
        n = head->next->next;
        head->next->next = head;
        head -> next = swapPairs(n);
        return m;
    }
}

//昨天学到的递归。。。
