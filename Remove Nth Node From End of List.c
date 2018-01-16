/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

    struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
    {
        int i = 0;
        struct ListNode *p;
        struct ListNode *m;
        p = head;
        m = head;
        while (p->next !=NULL)
        {
            p = p-> next;
            i++;
        }
        
        int c = 1;
        
        if (i==0)
        {
             free (head);  
             return NULL;
        }
        
        else
        { 
            int b = i - n + 1;
            if (b == 0)
            {
                head = head->next;
                return head;
            }
            else
           {
            while (c<b)
            {
                head = head-> next;
                c++;
            }
            p = head->next;
            head-> next = head->next->next;
            free (p);
            return m;
           }
        }
   
    
    }
