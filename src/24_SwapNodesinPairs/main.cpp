#include <string>
#include <set>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "via_list.h"

using namespace std;

//1->2->3->4, you should return the list as 2->1->4->3.
typedef VIA::ListNode<int> ListNode;

class Solution
{
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = NULL, *p1 = NULL, *p_before = NULL;

        if (head == NULL || head->next == NULL) return head;

        p = head;
        p1 = p->next;
        head = p1;

        while (true) {
            if (p_before != NULL) p_before->next = p1;
            p->next = p1->next;
            p1->next = p;

            p_before = p;

            p = p->next;
            if (p == NULL) break;

            p1 = p->next;
            if (p1 == NULL) break;
        }

        return head;
    }
};

TEST(test_Solution, test_1)
{
    //Solution solution;

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

    VIA::ListNode<int> *p1;
    vector<int> c1 = {1,2,3};
    VIA::ViaList::initList(p1, c1);
    VIA::ViaList::printList(p1);

    Solution solution;
    ListNode* p = solution.swapPairs(p1);
    VIA::ViaList::printList(p);
    //int32_t ret = RUN_ALL_TESTS();
    //LOG(INFO) << "ret:" << ret;
    //cout << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}

