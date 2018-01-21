/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* verse(struct ListNode* p)
{
    if (p ==NULL||p->next == NULL)
    {
        return p;
    }
    struct ListNode* root;
    root = verse (p->next);
    p->next->next = p;
    p->next = NULL;
    return root;
}

bool isPalindrome(struct ListNode* head) {
    if (head ==NULL||head->next ==NULL)
    {
        return true;
    }
    struct ListNode *p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    p3->next= NULL,p3->val = NULL ;
    struct ListNode *p5 = p3;
    struct ListNode *p1 = head;
    while (p1!=NULL)
    {
        struct ListNode *p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
        p4->val = p1->val;
        p4->next = NULL;
        p3->next = p4;
        p3 = p3->next;
        p1 = p1->next;
    }
    struct ListNode *p = verse (head);
    p5 = p5->next;
    while (p!=NULL)
    {
        if (p->val != p5->val)
        {
            return false;
        }
        p = p->next;
        p5 = p5->next;
    }
    return true;
}
