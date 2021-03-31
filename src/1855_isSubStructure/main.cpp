#include "via_util.h"


class Solution
{
public:
	bool isSubStructure(TreeNode* A, TreeNode* B)
    {
		log("isSubSt");
		A->print();
		B->print();
		if (A==nullptr || B==nullptr) return false;

		vector<TreeNode*> rstA;
		inorderTree(A, rstA);

		for (auto iter = rstA.begin(); iter != rstA.end(); ++iter) {
			if (checkEqual(*iter, B)) {
				cout << (*iter)->val << endl;
				return true;
			}
		}
		return false;
    }


	bool checkEqual(const TreeNode* const A, const TreeNode* const B) {
		if (A == nullptr) return false;
		if (B->val != A->val) return false;
		if (B->left != nullptr && !checkEqual(A->left, B->left)) return false;
		if (B->right != nullptr && !checkEqual(A->right, B->right)) return false;
		return true;
	}

	void inorderTree(TreeNode* p, vector<TreeNode*> &rst) {
		if (p == nullptr) return;
		if (p->left != nullptr) {
			inorderTree(p->left, rst);
		}
		rst.push_back(p);
		if (p->right != nullptr) {
			inorderTree(p->right, rst);
		}
	}

	void inorder(TreeNode* p, vector<int> &rst) {
		if (p == nullptr) return;
		if (p->left != nullptr) {
			inorder(p->left, rst);
		}
		rst.push_back(p->val);
		if (p->right != nullptr) {
			inorder(p->right, rst);
		}
	}

	void preorder(TreeNode* p, vector<int> &rst) {
		if (p == nullptr) return;
		rst.push_back(p->val);
		if (p->left != nullptr) {
			preorder(p->left, rst);
		}
		if (p->right != nullptr) {
			preorder(p->right, rst);
		}
	}

	bool inTree(vector<int> rstA, vector<int> rstB) {
		auto iter = rstA.begin();
		while((iter = find(iter, rstA.end(), rstB[0])) != rstA.end()) {
			auto iter_tmp = iter;
			auto iterB = rstB.begin();
			while (iterB != rstB.end() && iter_tmp != rstA.end()) {
				if (*iter_tmp != *iterB) {
					break;
				}
				++iterB;
				++iter_tmp;
			}
			if (iterB == rstB.end()) return true;
			++iter;
		}
		return false;
	}
};

TEST(test_Solution, test_1)
{
    Solution solution;

//    vector<int> v1 = {3,4,5,1,2};
//    vector<TreeNode> t1;
//    initTree(v1, t1);
//
//    vector<int> v2 = {4,1};
//    vector<TreeNode> t2;
//    initTree(v2, t2);
//
//    TreeNode* p1 = (TreeNode*)(void*)(&t1[0]);
//    TreeNode* p2 = (TreeNode*)(void*)(&t2[0]);
//
//    EXPECT_EQ(solution.isSubStructure(p1, p2), true);

    vector<int> v1 = {10,12,6,8,3,11};
	vector<TreeNode> t1;
	initTree(v1, t1);

	vector<int> v2 = {10,12,6,8};
	vector<TreeNode> t2;
	initTree(v2, t2);

	TreeNode* p1 = (TreeNode*)(void*)(&t1[0]);
	TreeNode* p2 = (TreeNode*)(void*)(&t2[0]);
	p1->print();
	p2->print();

	EXPECT_EQ(solution.isSubStructure(p1, p2), true);


//	TreeNode g(2);
//	TreeNode h(3);
//	TreeNode i(1, &g, &h);
//	TreeNode j(1);
//	TreeNode k(3, &j, nullptr);
//    EXPECT_EQ(solution.isSubStructure(&i, &k), false);



}
