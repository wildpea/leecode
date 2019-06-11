#include <string>
#include <set>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

/**
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void pt_list(ListNode* head) {
    ListNode* p = head;
    while (p != NULL)  {
        cout << p->val << endl;
        p = p->next;
    }
    delete p;
}

void addList(ListNode* &p, int i) {
    if (p == NULL) {
        p = new ListNode(i);
        p->next = NULL;
    }
    else {
        p->next = new ListNode(i);
        p = p->next;
    }
}

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* p = NULL;

        while (l1 != NULL || l2 != NULL) {

            if (l1 == NULL || (l1 != NULL && l2 != NULL && l1->val > l2->val)) {
                addList(p, l2->val);
                l2 = l2->next;
            } else {
                addList(p, l1->val);
                l1 = l1->next;
            }

            if (head == NULL) head = p;
        }

        delete p;
        return head;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    ListNode* head_1 = NULL;
    ListNode* p = NULL;
    for (int i = 0; i < 10; ++i)
    {
        addList(p, i);
        if (head_1 == NULL) head_1 = p;
        //cout << "p: " << p << ", head: " << head_1 << endl;
    }
    pt_list(head_1);

    ListNode* head_2 = NULL;
    p = NULL;
    for (int i = 2; i < 12; ++i)
    {
        addList(p, i);
        if (head_2 == NULL) head_2 = p;
        //cout << "p: " << p << ", head: " << head_1 << endl;
    }
    pt_list(head_2);

    cout << "-------------------" << endl;
    ListNode* rt = solution.mergeTwoLists(head_1, head_2);
    pt_list(rt);
    delete p;
    delete rt;
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
    LOG(INFO) << "ret:" << ret;

    google::ShutdownGoogleLogging();
    return 0;
}

