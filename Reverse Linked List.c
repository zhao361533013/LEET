/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* p = head;
    struct ListNode* q = head;
    if( head ==NULL)
    {
        return head;
    }
   if (head ->next ==NULL)
   {
       return head;
   }
    while (head->next != NULL)
    {
        q = head;
        head = head->next;
    }
    q->next = NULL;
    head ->next = reverseList(p);
    return head;
}
/// 自己的做法实在有点蠢  下面贴的是快速的方法

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL||head->next==NULL)
    return head;
    struct ListNode *root=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return root;
}
