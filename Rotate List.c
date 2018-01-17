/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int i = 1 ;
    struct ListNode* m = head;
    struct ListNode* n = head;
    while (head == NULL||k == 0||head->next == NULL)
    {
        return head;
    }
    while (m->next != NULL)
    {
        m = m->next;
        i++;
    }
    while( k > i )
    {
        k = k - i;
    }
    int a = i - k;
    if (a == 0)
    {
        return head;
    }
    int b;
    for (b = 0;b<a-1;b++)
    {
        n = n->next;
    }
    struct ListNode* q = n->next;
    n->next = NULL;
    m->next = head;
    return q;
 }


// 改进后
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
 
    if (!head || k == 0) return head;

	struct ListNode* lastNode = head;
	int n = 1;
	while (lastNode->next)
	{
		lastNode = lastNode->next;
		n++;
	}

	k = k%n;		
	if (k == 0) return head;
	k = n - k;

	lastNode->next = head;
	struct ListNode *newHead = head;

	for (int i = 0; i < k - 1; i++)
		newHead = newHead->next;
		
	head = newHead->next;
	newHead->next = NULL;
	return head;
 
}
