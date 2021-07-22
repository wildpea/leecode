#include "via_util.h"

class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *ab = headA;
		ListNode *bb = headB;
		bool switched = false;
		while (true) {
			if (ab == bb) return ab;

			if (ab->next != NULL)
				ab = ab->next;
			else if (switched){
				return NULL;
			} else {
				ab = headB;
				switched = true;
			}

			if (bb->next != NULL)
				bb = bb->next;
			else {
				bb = headA;
			}
		}
	}
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.run("III"), 3);
}
