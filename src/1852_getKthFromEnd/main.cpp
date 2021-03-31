#include "via_util.h"

class Solution
{
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
    	if (k == 0) {return nullptr;}
    	if (head == nullptr) {return head;}
    	return inner(head, k);
    }

    ListNode* inner(ListNode* head, int &k) {
    	ListNode *p;
    	if (head->next != nullptr) {
    		p = inner(head->next, k);
    		--k;
    		if (k == 0) {
    			return head;
    		}
    	} else {
    		--k;
    		if (k == 0) return head;
			return nullptr;
    	}

    	return p;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    ListNode *p = solution.getKthFromEnd(&e, 1);
    if (p != nullptr)
    	p->print();
    //EXPECT_EQ(solution.getKthFromEnd(&a, 3), 3);
}
