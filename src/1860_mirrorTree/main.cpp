#include "via_util.h"

class Solution
{
public:
	TreeNode* mirrorTree(TreeNode* root) {
		TreeNode* p = root;
		if (root == nullptr) {
			return p;
		}
		TreeNode *right = root->right;
		p->right = mirrorTree(root->left);
		p->left = mirrorTree(right);

		return p;
	}
};

TEST(test_Solution, test_1)
{
    Solution solution;
    vector<int> v = {4,2,7,1,3,6,9};
    vector<TreeNode> p;
    initTree(v, p);
    p[0].print();

    TreeNode * p2 = solution.mirrorTree(&(p[0]));
    p2->print();
    //EXPECT_EQ(solution.mirrorTree(&(p[0])));
}
