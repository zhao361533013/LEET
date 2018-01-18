/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
     struct ListNode* newp1 = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    struct ListNode* p1 =NULL;
    newp1 -> next = head;
    struct ListNode* p7;
    struct ListNode* p6 = newp1;
    while (head == NULL || m == n)
    {
        return head;
    }
    int i;
    for (i=1;i<m;i++)
    {
        p6 = head;
        head = head->next;
    }
    for ( i = m;i<n||i==n;i++)
    {
        struct ListNode* newp = (struct ListNode*)malloc(sizeof(struct ListNode));
        newp->val = head-> val;
        newp->next = p1;
        p1 = newp;
        head = head->next;
    }
    struct ListNode* p8 = p1;
    for (i = m; i< n||i==n;i++)
    {
        p7 = p8;
        p8 = p8->next;
    }
    p6->next = p1;
    p7->next = head;
    return newp1->next;
}
