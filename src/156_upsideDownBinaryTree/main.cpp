#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;



/**
 * Definition for a binary tree node. */
 struct TreeNode {
     int val;
     TreeNode *left, *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     void p() {
    	 std::deque<TreeNode*> d;
    	 d.push_back(this);
    	 while (d.size() != 0) {
    		 TreeNode* r = d.front();
    		 if (r == nullptr) {
    			 cout << "#";
    			 d.pop_front();
    			 continue;
    		 }
    		 cout << r->val;
    		 //if (r->left != nullptr)
    			 d.push_back(r->left);
    		 //if (r->right != nullptr)
    			 d.push_back(r->right);
    		 d.pop_front();
    	 }
//    	 cout << val;
//    	 if (left != nullptr) {
//    		 left->p();
//    	 } else {
//    		 cout << "#";
//    	 }
//    	 if (right != nullptr) {
//    		 right->p();
//    	 } else {
//    		 cout << "#";
//    	 }
     }
};

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {

    	if (root == nullptr) {
			return root;
		} else if (root->left == nullptr) {
			return root;
		}

    	TreeNode * right = nullptr;
    	TreeNode * rst = inner(root, right);
    	return rst;
    }

    TreeNode* inner(TreeNode *root, TreeNode* &right) {
    	TreeNode* t = root;

    	//尾巴上
    	if (t != nullptr && t->left != nullptr && t->left->left == nullptr) {
    		cout << "in 2, switch" << endl;
    		TreeNode *rst = t->left;
    		rst->left = t->right;
    		rst->right = t;
			t->left = nullptr;
			t->right = nullptr;
			right = t;
			rst->p();
			return rst;
    	}

		TreeNode* rst = inner(t->left, right);
		right->left = t->right;
		right->right = t;
		t->left = nullptr;
		t->right = nullptr;
		right = t;

		return rst;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    TreeNode t5 = TreeNode(5);
    TreeNode t4 = TreeNode(4);
    TreeNode t3 = TreeNode(3);
    TreeNode t2 = TreeNode(2, &t4, &t5);
    TreeNode t1 = TreeNode(1, &t2, &t3);


//    TreeNode t1 = TreeNode(1);
//    TreeNode t3 = TreeNode(3);
//    TreeNode t2 = TreeNode(2,&t3,&t1);
//    TreeNode t5 = TreeNode(5);
//    TreeNode t4 = TreeNode(4, &t5, &t2);

    t1.p();
    cout << endl;
    TreeNode *rst = solution.upsideDownBinaryTree(&t1);
   rst->p();
    //EXPECT_EQ(solution.run(&t5), 3);
}

DEFINE_string(cmd, "", "cmd");
DEFINE_string(logdir, "./", "logdir");


int32_t main(int32_t argc, char **argv)
{
    gflags::ParseCommandLineFlags(&argc, &argv, false);
    testing::InitGoogleTest(&argc, argv);
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = FLAGS_logdir;

    //LOG(INFO) << FLAGS_cmd;

    int32_t ret = RUN_ALL_TESTS();
    //LOG(INFO) << "ret:" << ret;
    cout << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}

