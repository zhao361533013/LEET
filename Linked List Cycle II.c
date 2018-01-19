/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast , *slow;
    fast = head;
    slow = head;
    while (fast&&slow&&fast ->next!= NULL&&fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    if (fast ==NULL || fast ->next ==NULL||fast->next->next ==NULL)
    {
        return NULL;
    }
    if(fast == slow)
    {
        slow = head;
        while (slow != fast)
        {
         slow = slow-> next;
        fast = fast ->next;
        }
    }
       return fast;
}

/***1.如何判断是否有环？如果有两个头结点指针，一个走的快，一个走的慢，那么若干步以后，快的指针总会超过慢的指针一圈。


2.如何计算环的长度？第一次相遇（超一圈）时开始计数，第二次相遇时停止计数。

3.如何判断环的入口点：碰撞点p到连接点的距离=头指针到连接点的距离，因此，分别从碰撞点、头指针开始走，相遇的那个点就是连接点。

为什么呢？需要一个简单的计算过程：
（1）当fast与slow相遇时，show肯定没有走完链表，而fast已经在还里走了n（n>= 1）圈。假设slow走了s步，那么fast走了2s步。fast的步数还等于s走的加上环里转的n圈，所以有：
2s = s + nr。因此，s = nr。
（2）设整个链表长为L，入口据相遇点X，起点到入口的距离为a。因为slow指针并没有走完一圈，所以：
a + x = s，带入第一步的结果，有：a + x = nr = (n-1)r + r = (n-1)r + L - a；即：
a = (n-1)r + L -a -x;
这说明：从头结点到入口的距离，等于转了(n-1)圈以后，相遇点到入口的距离。因此，我们可以在链表头、相遇点各设一个指针，每次各走一步，两个指针必定相遇，且相遇第一点为环入口点。
也许大家有一个问题，就是为什么“当fast与slow相遇时，show肯定没有走完链表”。这个问题比较坑，我也没有找到很好的证明。不过大家自己画几个试试，会发现的确是这样。

4.如何判断两个链表（不带环）是否相交？将其中的一个链表首尾相连，然后判断另一个链表是否带环即可。这个比较简单，程序就省略了。
