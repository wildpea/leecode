#include <string>
#include <set>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rt = {-1,-1};

        int l = 0, r = nums.size() - 1;
        if (r < l) return rt;
        int i = -1;
        if (nums[l] == target) {
            i = l;
        } else if (nums[r] == target) {
            i = r;
        } else {
            i = bisearch(nums, l, r, target);
        }
        if (i != -1) {
            rt.clear();
            l = i, r = i;
            while (l >= 0) {
                if (nums[l] < target) break;
                --l;
            }
            rt.push_back(++l);
            while (r < nums.size()) {
                if (nums[r] > target) break;
                ++r;
            }
            rt.push_back(--r);
        }

        return rt;
    }

    int bisearch(vector<int>& nums, int &l, int &r, int target) {
        if (l >= r) return -1;

        int m = (l + r) / 2;
        if (nums[m] == target) return m;

        if (m == l || m == r) return -1;

        if (nums[m] > target)
            return bisearch(nums, l, m, target);
        else
            return bisearch(nums, m, r, target);
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<int> n1 = {5,7,7,8,8,10};
    vector<int> n11 = {3,4};
    EXPECT_EQ(solution.searchRange(n1, 8), n11);

    vector<int> n2 = {5,7,7,8,8,10};
    vector<int> n22 = {-1,-1};
    EXPECT_EQ(solution.searchRange(n2, 6), n22);

    vector<int> n3 = {};
    EXPECT_EQ(solution.searchRange(n3, 6), n22);

    vector<int> n4 = {5};
    vector<int> n44 = {0,0};
    EXPECT_EQ(solution.searchRange(n4, 5), n44);




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

