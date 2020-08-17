#include <string>
#include <set>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "trace.h"

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target) {
//        for (int i = 0, len = nums.size(); i < len; ++i)
//        {
//            if (nums[i] == target) return i+1;
//        }
        int l = 0;
        int r = nums.size() - 1;
        if (r < l) return -1;
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return bisearch(nums, l, r, target);
    }

    int bisearch(vector<int>& nums, int &l, int &r, int target) {
        if (l >= r) return -1;
        if (nums[l] < nums[r] && (
                (nums[l] < target && nums[r] < target)
              ||(nums[l] > target && nums[r] > target)
        )) return -1;

        int ret = 0;

        int m = (l + r) / 2;
        if (nums[m] == target) return m;

        if (m == l || m == r) return -1;

        ret = bisearch(nums, l, m, target);
        if (ret > 0) return ret;

        ret = bisearch(nums, m, r, target);
        if (ret > 0) return ret;

        return -1;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<int> n1 = {23,34,42,51,66,71,0,12,17,22};
    EXPECT_EQ(solution.search(n1, 42), 2);

    EXPECT_EQ(solution.search(n1, 81), -1);

    EXPECT_EQ(solution.search(n1, 12), 7);

    vector<int> n2 = {4,5,6,7,0,1,2};
    EXPECT_EQ(solution.search(n2, 0), 4);

    vector<int> n3 = {};
    EXPECT_EQ(solution.search(n3, 5), -1);
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

    //LOG(INFO) << FLAGS_cmd;

    int32_t ret = RUN_ALL_TESTS();
    //LOG(INFO) << "ret:" << ret;
    cout << "result : " << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}

