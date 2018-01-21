/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void exchange(struct ListNode *p1, struct ListNode *p2)
{
    int i = p1->val;
    if (p1->val > p2->val)
    {
        p1->val = p2->val;
        p2->val = i;
    }
}
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head ==NULL || head->next ==NULL)
    {
        return head;
    }
    struct ListNode* p = (struct ListNode*)malloc (sizeof(struct ListNode));
    p ->val = head->val;
    p ->next = NULL;
    struct ListNode* p1 = head;
    struct ListNode *p2 = head->next;
    struct ListNode*p3 = p;
    struct ListNode*p6;
    while (p2)
    {
        struct ListNode* p4 = (struct ListNode*)malloc (sizeof(struct ListNode));
        struct  ListNode* p5;
        p4->val = p2->val;
        p4->next = p3;
        p3 = p4;
        p5 = p4;
        while (p5->next!=NULL)
        {
            exchange (p5,p5->next);
            p5 = p5->next;
        }
        p2 = p2->next;
        p6 = p4;
    }
    return p6;
}
// 运行速度太慢了 贴上速度快的版本：

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if ( !head || !head->next ) {
        return head;
    }
    struct ListNode dummyNode = { .val = 0, .next = head };
    struct ListNode * dummyPtr = & dummyNode, *cur = head->next, *pre = head,* next = head->next, *temp1, *temp2;
    while ( cur != NULL ) {
        next = cur->next;
        // printf("cur %d, pre %d ", cur->val, pre->val );
        if ( cur->val < pre->val ) {
            temp1 = pre;
            pre = dummyPtr;
            while ( pre->next && pre->next->val < cur->val ) {
                pre = pre->next;
                // printf("move pre to %d ", pre->val );
            }
            temp2 = pre->next;
            // printf("subhead %d ",temp2->val);
            pre->next = cur;
            cur->next = temp2;
            temp1->next = next;
            pre = temp1;
            cur = next;
            // printf("after sorting: cur %d, pre %d ", cur->val, )
        } else {
            // printf("passed %d\n", cur->val );
            pre = cur;
            cur = next;
        }
        // pre = next;
        
        // cur = next;
    }
    return dummyNode.next;
}
