struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;

        ListNode *p = new ListNode(0);
        ListNode *head = p;
        int x = 0, y = 0, t = 0, s = 0;
        while(true)
        {
            x = l1 == NULL ? 0 : l1->val;
            y = l2 == NULL ? 0 : l2->val;
            s = x + y + t;
            t = s / 10;

            p->val = s % 10;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;

            if (l1 == NULL && l2 == NULL && t == 0) break;

            p->next = new ListNode(0);
            p = p->next;
        }
        return head;
    }

};

