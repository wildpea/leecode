#include "via_util.h"

class Solution
{
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		return isEqual(root->left, root->right);
	}

	bool isEqual(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr) return true;
		if (root1 != nullptr && root2 == nullptr) return false;
		if (root1 == nullptr && root2 != nullptr) return false;
		if (root1->val != root2->val) return false;
		return isEqual(root1->left, root2->right) && isEqual(root1->right, root2->left);
	}
};

TEST(test_Solution, test_1)
{
    Solution solution;
    //vector<int> i = {1,2,2,3,4,4,3};
    //vector<int> i = {1,2,2,MY_NULL,3,MY_NULL,3};
    vector<int> i = {1,2,2,3,MY_NULL,MY_NULL,3};
    vector<TreeNode> p;
    initTree(i, p);
    p[0].print();

    EXPECT_EQ(solution.isSymmetric(&(p[0])), true);
//    EXPECT_EQ(solution.isSymmetric(&(p[0])), false);
    //EXPECT_EQ(solution.run("III"), 3);
}
