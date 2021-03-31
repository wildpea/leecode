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
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> rst;
    	if (root == nullptr) {return rst;}

    	TreeNode *p = root;
    	deque<TreeNode*> v;
    	v.push_back(p);
    	while (v.size() > 0) {
    		vector<int> r;
    		for (auto iter = v.begin(); iter != v.end(); ++iter) {
    			r.push_back((*iter)->val);
    		}
    		rst.push_back(r);
    		int len = v.size();
    		for (int i = 0; i < len; ++i) {
    			TreeNode* top = v.front();
    			if (top->left != nullptr) v.push_back(top->left);
    			if (top->right != nullptr) v.push_back(top->right);
    			v.pop_front();
    		}
    	}
    	return rst;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    TreeNode t1 = TreeNode(1);
    TreeNode t3 = TreeNode(3);
    TreeNode t2 = TreeNode(2,&t3,&t1);
    TreeNode t5 = TreeNode(5);
    TreeNode t4 = TreeNode(4, &t5, &t2);

    vector<vector<int>> rst = solution.levelOrder(&t4);
    for (auto iter = rst.begin(); iter != rst.end(); ++iter){
    	for (auto iter1 = iter->begin(); iter1 != iter->end(); ++iter1) {
    		cout << *iter1;
    	}
    	cout << endl;
    }
//    EXPECT_EQ(solution.run("III"), 3);
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

