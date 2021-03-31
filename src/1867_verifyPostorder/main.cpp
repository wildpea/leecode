#include "via_util.h"

class Solution
{
public:
    bool verifyPostorder(const vector<int>& postorder) {
    	int len = postorder.size();
    	if (len == 0 || len == 1) return true;
    	return verifySub(postorder, 0, len-1);
    }

    bool verifySub(const vector<int> &postorder, int start, int end) {
    	cout << "in verify: " << postorder[end] << ", " << start << ", " << end << endl;
    	int len = end - start + 1;
    	if (len <= 1) return true;
		int sp = start-1;
		bool find = false;
		int c = postorder[end];
		for (int i = start; i <= end; ++i) {
			if (postorder[i] < c) {
				if (find) {log(0);return false;}
				++sp;
			} else {
				log("find");
				find = true;
			}
		}

		const int left_start = start, left_end = sp;
		const int right_start = sp + 1, right_end = end-1;

		if (right_end >= right_start && postorder[right_end] < c) {
			log(1);
			return false;
//		} else if (left_end - left_start == 0 && right_end - right_start != 0) {
//			log(2);
//			return false;
		} else if (left_end >= left_start && postorder[left_end] > c) {
			log(3);
			return false;
		}

		bool rst = false;
		if (left_end > left_start) {
			if (!verifySub(postorder, left_start, left_end)) {
				return false;
			}
		}
		if (right_end > right_start) {
			if (!verifySub(postorder, right_start, right_end)) {
				return false;
			}
		}

		return true;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;
//    vector<int> v = {1,6,3,2,5};
//    vector<int> v = {1,3,2,6,5};
//    vector<int> v = {4, 8, 6, 12, 16, 14, 10};
    vector<int> v = {4, 6, 7, 5};
    vector<TreeNode> p;
    initTree(v, p);

    EXPECT_EQ(solution.verifyPostorder(v), true);
}
