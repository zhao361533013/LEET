/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *p = head;
    struct ListNode *p2 = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* p3 = p2;
    p2->next = head;
    if (head ==NULL)
    {
        return NULL;
    }
    while (p != NULL)
    {
        if (p->val == val)
        {
            //printf ("%d  %d\n",p->val,p2->val);
            p2->next = p->next;
            p = p->next;
        }
        else
        {
        p = p->next;
        p2 = p2->next;
        }
    }
    return p3->next;
}
// 自己的做法速度太 慢了 贴一个运行速度快的方法， 感觉思路是一样的。。。。。。 果然 是因为忘记删除printf 语句了，，，，，，，，
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode* previous = NULL;
    struct ListNode* current = head;
    
    while(current != NULL){        
        if(current->val == val){
            if(previous == NULL){
                current = current->next;
                head->next = NULL;
                head = current;
            }
            else{
            previous->next = current->next;
            current->next = NULL;     
            current = previous->next;
            }
        }        
        else{
            previous = current;
            current = current->next;
        }   
    }
    return head;
}
