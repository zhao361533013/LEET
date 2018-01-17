/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head) {
    struct ListNode *p = head;
    while (p->next) {
        if (p->val != p->next->val) {
            p = p->next;
        }
        else {
            struct ListNode *tmp = p->next;
            p->next = p->next->next;
            free(tmp);
        }
    }
}

return head;
}

//下面那种是自己做的 太蠢了 忘了就好 忘了就好。。。。。。。


















/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    if (head == NULL)
    {
        return head;     
    }
    struct ListNode *newp = head;
    struct ListNode *newL = (struct ListNode*)malloc(sizeof(struct ListNode));
    newL->val = NULL;
    newL-> next = NULL;
    struct ListNode* newp1 = newL;
    struct ListNode* newp2 = newp1;
    while (newp != NULL)
    {
        int o = 1;
        int a = newp->val;
        printf ("%d ",a);
        struct ListNode* newp1 = newL;
        while (newp1->next != NULL)
        {
            if(a == newp1->next->val)
            {
                o++;
            }
            newp1 = newp1->next;
        }
        if (o == 1)
        {
        struct ListNode *newM = (struct ListNode*)malloc(sizeof(struct ListNode));
        newp2->next = newM;
        newM ->val = a;
        newM->next =NULL;
        newp2 = newM;
            
        }
        newp = newp->next;
    }
      return newp1->next;
}


