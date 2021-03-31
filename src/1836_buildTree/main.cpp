#include "via_util.h"

class Solution
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		VIA::ViaSTL::printC<int>(preorder, "preorder");
		VIA::ViaSTL::printC<int>(inorder, "inorder");
		int len = inorder.size();
		if (len == 0) {return nullptr;}

		TreeNode *head = new TreeNode(preorder[0]);
		preorder.erase(preorder.begin());
		TreeNode *p = head;

		auto iter = find(inorder.begin(), inorder.end(), head->val);
		vector<int> leftOrder(inorder.begin(), iter);
		vector<int> rightOrder(iter + 1, inorder.end());

		if (preorder.size() > 0) {
			TreeNode* left = buildTree(preorder, leftOrder);
			p->left = left;
		}

		if (preorder.size() > 0) {
			TreeNode* right = buildTree(preorder, rightOrder);
			p->right = right;
		}

		return head;
	}
};

TEST(test_Solution, test_1)
{
    Solution solution;

//    vector<int> v1= {3,9,20,15,7};	//前序
//    vector<int> v2= {9,3,15,20,7};	//中序
    vector<int> v1 = {1};
    vector<int> v2 = {1};
    TreeNode *p = solution.buildTree(v1, v2);
    p->p();
    //EXPECT_EQ(solution.buildTree(v1, v2), 3);
}


