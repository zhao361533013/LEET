/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* p1, *p2;
    p1 = headA;
    p2 = headB;
    int a = 1;
    int b = 1;
    int c ;
    while (headA ==NULL|| headB == NULL)
    {
        return NULL;
    }
    while (p1->next != NULL)
    {
        p1 = p1->next;
        a++;
    }
    while (p2->next != NULL)
    {
        p2 = p2->next;
        b++;
    }
    if(p1 != p2)
    {
        return NULL;
    }
    p1 = headA;
    p2 = headB;
    if (a > b)
    {
        int i;
        c = a-b;
        for (i = 0; i < c; i++ )
        {
            p1 = p1->next;
        }
        while (p1!=p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
    if (a < b||a==b)
    {
        int i;
        c = b-a;
         for (i = 0; i < c; i++ )
        {
            p2 = p2->next;
        }
        while (p1!=p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
    return p2;
}

//solution:
Approach #2 (Hash Table) [Accepted]

Traverse list A and store the address / reference to each node in a hash set. Then check every node bi in list
B: if bi appears in the hash set, then bi is the intersection node.

Complexity Analysis

Time complexity : O(m+n) Space complexity : O(m) or O(n).
