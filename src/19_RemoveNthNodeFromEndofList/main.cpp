#include <string>
#include <set>
#include <map>
#include <list>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) return head;

        ListNode* a = head;

        int len = 0;
        while (a != NULL) {
            ++len;
            a = a->next;
        }
        cout << len << endl;

        if (n > len) n = len;
        a = head;

        if (n == len) {
            head = head->next;
            delete a;
            return head;
        }

        int index = 0;
        while (index < len - n - 1)
        {
            a = a->next;
            ++index;
        }
        ListNode* tmp = a->next;
        a->next = tmp->next;
        delete tmp;

        return head;
    }
};


void pt_list(ListNode* head) {
    ListNode* p = head;
    while (p != NULL)  {
        cout << p->val << endl;
        p = p->next;
    }
}

TEST(test_Solution, test_1)
{
    Solution solution;

    ListNode* head = NULL;
    ListNode* p = NULL;
    for (int i = 0; i < 10; ++i)
    {
        if (p == NULL) {
            p = new ListNode(i);
            p->next = NULL;
            head = p;
        }
        else {
            p->next = new ListNode(i);
            p = p->next;
        }
    }

    pt_list(head);
    cout << "-------------------" << endl;
    ListNode* rt = solution.removeNthFromEnd(head, 10);
    pt_list(rt);
    //EXPECT_EQ(solution.removeNthFromEnd(head, 2), p);

//    ListNode* next = head->next;
//    while (head != NULL) {
//        delete head;
//        head = next;
//        next = head->next;
//    }
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

    list<int> lt = {1,2,3};
    int32_t ret = RUN_ALL_TESTS();
    LOG(INFO) << "ret:" << ret;

    google::ShutdownGoogleLogging();
    return 0;
}

