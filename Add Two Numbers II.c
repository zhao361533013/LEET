/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int size (struct ListNode* p)
{
    int i = 0;
    while (p )
    {
        p = p->next ;
        i++;
    }
    return i;
}
struct ListNode* jinwei(struct ListNode *pre,struct ListNode* p)
{
    if (p->next == NULL)
    {
        if (p->val > 10 || p->val == 10)
        {
            pre->val +=1;
            p-> val  -=10;
        }
        return p;    
    }
    p->next = jinwei (p,p->next);
    if (p->val > 10 || p->val == 10)
    {
        pre->val += 1;
        p->val -=10;
    }
    return p;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1,*p2,*p3,*p4;
    int a,b,i;
    p1 = l1; 
    p2 = l2;
    a = size (p1);
    b = size (p2);
    struct ListNode *q = (struct ListNode*)malloc(sizeof(struct ListNode));
    p1 = l1; p2 = l2;
    q->next =NULL; q-> val = NULL;
    if (a > b)
    {
        int c = a - b;
        for (i = 0;i<c;i++)
        {
        struct ListNode *q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        q1->val = 0;
        q1->next = p2;
        p2 = q1;
        }
    }
    p3 = p2;
    if (a < b)
    {
        int c = b - a;
        for (i = 0;i<c;i++)
        {
        struct ListNode *q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        q1->val = 0;
        q1->next = p1;
        p1 = q1;
        }
    }
    p4 = p1;
    p1 = l1; p2 = l2;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    head->val = NULL;
    struct ListNode *phead = head;
    while (p3)
    {
       struct ListNode *q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        q1->val = p3->val + p4->val;
        q1->next = NULL;
        head ->next = q1;
        head = head->next;
        p3 = p3->next;
        p4 = p4->next;
    }
    jinwei (phead,phead->next);
    if (phead->val == 1)
    {
        return phead;
    }
    return phead->next;
}
// 这道题本来是要放弃了的，结果百度了好几分代码都没通过 有了一点思路开始重新写，主要思路是将少的那一个链表补到和多的一样，补的位全部填零，
然后计算每个位置的值，再使用递归将进位解决， 最后返回一个新链表，其实可以用反转链表做 很简单 可是题目要求不许这么做。。。。。还有一点要
注意的是 初始化一个指针指向的空间的时候 要对其进行赋值 哪怕是NULL值。 虽然这么麻烦的方法 ，，，， 在 运行时间上击败了80%多的人 哈哈
