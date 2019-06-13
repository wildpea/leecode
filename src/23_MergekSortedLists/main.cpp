#include <string>
#include <set>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "via_list.h"
#include "trace.h"

using namespace std;

/**
 * Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 */
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
typedef VIA::ListNode<int> ListNode;

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *p = NULL, *head = NULL;
        multimap<int, int> mp;
        int len = lists.size();
        bool init = false;
        while (true) {
            if (!init) {
                init = true;
                for (int i = 0; i < len; ++i)
                {
                    if (lists[i] != NULL) {
                        mp.insert(make_pair(lists[i]->val, i));
                    }
                }
            }

            if (mp.empty()) break;

            VIA::ViaList::addList(p, mp.begin()->first);
            if (head == NULL) head = p;

            int i = mp.begin()->second;
            lists[i] = lists[i]->next;

            mp.erase(mp.begin());

            if (lists[i] != NULL) {
                mp.insert(make_pair(lists[i]->val, i));
            }
        }

        return head;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;
    //EXPECT_EQ(solution.mergeKLists("III"), 3);
}

DEFINE_string(cmd, "", "cmd");
DEFINE_string(logdir, "./", "logdir");


int32_t main(int32_t argc, char **argv)
{
    InstallCoredumpHandle();
    gflags::ParseCommandLineFlags(&argc, &argv, false);
    testing::InitGoogleTest(&argc, argv);
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = FLAGS_logdir;
//[[1,4,5],[1,3,4],[2,6]]
    //LOG(INFO) << FLAGS_cmd;
    VIA::ListNode<int> *p1, *p2, *p3;
    vector<int> c1 = {1,4,5};
    vector<int> c2 = {1,3,4};
    vector<int> c3 = {2,6};
    VIA::ViaList::initList(p1, c1);
    VIA::ViaList::printList(p1);
    VIA::ViaList::initList(p2, c2);
    VIA::ViaList::printList(p2);
    VIA::ViaList::initList(p3, c3);
    VIA::ViaList::printList(p3);

    vector<ListNode*> vl = {p1, p2, p3};
    Solution solution;
    ListNode* p = solution.mergeKLists(vl);
    VIA::ViaList::printList(p);

    //int32_t ret = RUN_ALL_TESTS();
    //LOG(INFO) << "ret:" << ret;
    //cout << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}

