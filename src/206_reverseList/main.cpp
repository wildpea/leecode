#include <string>
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void p() {
    	cout << val;
    	if (next != nullptr) {
    		next->p();
    	}
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (head == nullptr || head->next == nullptr) return head;

    	ListNode *p = head, *p2 = p->next, *p3 = nullptr;
    	head->next = nullptr;
    	while (p2 != nullptr) {
    		p3 = p2->next;
    		p2->next = p;

    		p = p2;
    		p2 = p3;
    	}

    	return p;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    ListNode n5 = ListNode(5);
    ListNode n4 = ListNode(4, &n5);
    ListNode n3 = ListNode(3, &n4);
    ListNode n2 = ListNode(2, &n3);
    ListNode n1 = ListNode(1, &n2);

    n1.p();
    cout << endl;

    ListNode *r = solution.reverseList(&n1);
    r->p();

    cout << endl;
    //EXPECT_EQ(solution.run("III"), 3);
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

