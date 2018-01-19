/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    if (head ==NULL)
    {
        return head;
    }
    struct RandomListNode *p = head;
    struct RandomListNode *p2;
    struct RandomListNode *pHead = NULL;
    while (p)
    {
        p2 = p->next;
        struct RandomListNode *p1 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
        p1->label = p->label;
        p1->next  = p2;
        p1->random = NULL;
        p->next = p1;
        p = p2;
    }
    p = head;
    while (p)
    {       
        if (p->random != NULL)
        {
        p -> next-> random = p->random->next;
        }
        p = p->next->next;
    }
    p = head;
    while (p)
    {
        if (pHead !=NULL)
        {
            p2->next = p2->next->next;
            p2 = p2->next;
        }
        else 
        {
            pHead = p->next;
            p2 = pHead;
        }
        p -> next  = p->next->next;
        p = p->next;
    }
    return pHead;
}

这道题光明白问什么就用了好久。。。。。 还好看懂解析做出来了，不能直接复制的原因是因为你不能判断每一个节点你之前复制过没有。可以用Hash Map 来解决
 可是尴尬的是我现在不会。。。  找了好几个解析，这个方法我觉的也不错。
 思路：
 那么有没有办法可以不用额外空间来完成这个任务呢？还是有的，前面我们需要一个哈希表的原因是当我们访问一个结点时可能它的随机指针指向的结点还没有访问过，
 结点还没有创建，所以我们需要线性的额外空间。想避免使用额外空间，我们只能通过利用链表原来的数据结构来存储结点。基本思路是这样的，对链表进行三次扫描，
 第一次扫描对每个结点进行复制，然后把复制出来的新节点接在原结点的next，也就是让链表变成一个重复链表，
 就是新旧更替；第二次扫描中我们把旧结点的随机指针赋给新节点的随机指针，因为新结点都跟在旧结点的下一个，
 所以赋值比较简单，就是node.next.random = node.random.next，其中node.next就是新结点，因为第一次扫描我们就是把新结点接在旧结点后面。
 现在我们把结点的随机指针都接好了，最后一次扫描我们把链表拆成两个，第一个还原原链表，而第二个就是我们要求的复制链表。因为现在链表是旧新更替，
 只要把每隔两个结点分别相连，对链表进行分割即可。这个方法总共进行三次线性扫描，所以时间复杂度是O(n)。而这里并不需要额外空间，所以空间复杂度是O(1)。
 比起上面的方法，这里多做一次线性扫描，但是不需要额外空间 （http://blog.csdn.net/linhuanmars/article/details/22463599）
 http://blog.csdn.net/jiadebin890724/article/details/33827023
直接复制做法有问题，因为random是随意指向链表中的节点，复制random与复制next的过程有重复，而上面的做法却没有检查哪些节点是已经复制过的了
http://blog.csdn.net/sun20082567/article/details/36198817
