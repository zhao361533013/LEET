/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* newl = (struct ListNode*)malloc(sizeof (struct ListNode));
    struct ListNode* m = newl;
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    while (l1!= NULL || l2!= NULL){
        if (l1 == NULL)
        {
            struct ListNode* ne = (struct ListNode*)malloc(sizeof (struct ListNode));
            m-> next = ne;
            ne -> val = l2 -> val;
            ne -> next =  NULL;          
            m = ne;
            l2 = l2->next;
        }
        if (l2 == NULL && l1!= NULL)
        {
            struct ListNode* ne = (struct ListNode*)malloc(sizeof (struct ListNode));
            m-> next = ne;
            ne -> val = l1 -> val;
            ne -> next =  NULL;          
            m = ne;
            l1 = l1->next;
        }
        if(l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                struct ListNode* ne = (struct ListNode*)malloc(sizeof (struct ListNode));
                m-> next = ne;
                ne -> val = l1 -> val;
                ne -> next =  NULL;          
                m = ne;
                l1 = l1->next;
            }
         
        }
        if(l1 != NULL && l2 != NULL)
        {
           if (l1->val > l2->val)
             {
                struct ListNode* ne = (struct ListNode*)malloc(sizeof (struct ListNode));
                m-> next = ne;
                ne -> val = l2 -> val;
                ne -> next =  NULL;          
                m = ne;
                l2 = l2->next;
            }
        }
    }
    
    return newl->next;
}
