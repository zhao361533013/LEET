/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
   struct ListNode *p1,*p2;
    p1 = head;
    p2 = head;
    while (p1&&p2&&p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p2 == p1)
        {
            return true;
        }
    }
    return false;
}

// 一开始没看懂题。。。。 这是判断一个链表是否是一个环（回路）。 思路很简单 就是设置两个指针， 一个指针一次移动两位， 一个移动一位。
当两个指针相遇的时候，证明链表是一个回路。
