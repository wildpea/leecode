#include <string>
#include <set>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "via_list.h"
#include "via_stl.h"

using namespace std;

typedef VIA::ListNode<int> ListNode;
class Solution
{
public:

    void switchNode(ListNode *&p1, ListNode *&p2, ListNode *&p1_prev, ListNode *&p2_prev) {
        if (p1_prev != NULL) p1_prev->next = p2;
        p2_prev->next = p1;
        ListNode *p = p1->next;
        p1->next = p2->next;
        p2->next = p;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> vl(k);
        ListNode *start = NULL, *prev = NULL;
        while (true) {
            vl.clear();
            for (int i = 0; i < k; ++i)
            {
                if(head == NULL) goto a;
                ListNode *p = head;
                vl.push_back(p);
                head = head->next;
            }
            if (start == NULL) start = vl.back();
            for (int i = 0, j = vl.size() - 1; i < j; ++i, --j) {
                switchNode(vl[i], vl[j], i == 0 ? prev : vl[i - 1], vl[j - 1]);
                swap(vl[i], vl[j]);
            }
            prev = vl.back();
        }
        a:
        if (start == NULL) start = vl.front();
        return start;
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

    ListNode *p1;
    vector<int> c1 = {1,2,3,4,5,6,7};
    VIA::ViaList::initList(p1, c1);
    VIA::ViaList::printList(p1);

    Solution solution;
    ListNode* p = solution.reverseKGroup(p1, 9);
    VIA::ViaList::printList(p);

    //int32_t ret = RUN_ALL_TESTS();
    //LOG(INFO) << "ret:" << ret;
    //cout << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}

