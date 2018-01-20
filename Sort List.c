/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    struct ListNode *slow = head, *fast = head, *prev, *left, *right;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    left = sortList(head);
    right = sortList(slow);
    return mergeTwoLists(left, right);
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummyHead = {0}, *prev = &dummyHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    if (l1) prev->next = l1; else prev->next = l2;
    return dummyHead.next;
}


// 时间复杂度 Nlogn 的算法常见有 快速排序 和 归并排序
