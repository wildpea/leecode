#include <string>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:

    vector<int> reversePrint(ListNode* head) {
    	vector<int> x;
    	inner(head, x);
    	return x;
    }
    void inner(ListNode* head, vector<int> &v) {
    	if (head == nullptr) {
    		return;
    	}
    	if (head->next == nullptr) {
    		v.push_back(head->val);
    		return;
    	}

		v = reversePrint(head->next);
		v.push_back(head->val);


		//    	stack<int> x;
		//    	x.push(head->val);
		//    	while (head->next != nullptr) {
		//    		head = head->next;
		//    		x.push(head->val);
		//    	}
		//
		//    	while (x.size() > 0) {
		//    		v.push_back(x.top());
		//    		x.pop();
		//    	}
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    ListNode a(1);
    ListNode b(3);
    ListNode c(2);
    a.next = &b;
    b.next = &c;

    vector<int> rst = solution.reversePrint(&a);
    for (auto iter = rst.begin(); iter != rst.end(); ++iter) {
    	cout << *iter << endl;
    }
    //vector<int> v = {2,3,1};
    //EXPECT_EQ(solution.reversePrint(a), v);
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

