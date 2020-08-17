#include <string>
#include <set>
#include <map>
#include <algorithm>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums) {
        //1:
//        sort(nums.begin(), nums.end());
//        int len = nums.size();
//        return nums[len / 2];

        //2:
        int x = 0;
        int count = 0;
        for (int i = 0, len = nums.size(); i < len; ++i)
        {
            if (count == 0) {
                x = nums[i];
                ++count;
            }else if (x == nums[i]) {
                ++count;
            } else {
                count--;
            }
        }

        return x;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<int> v1 = {3,2,3};
    EXPECT_EQ(solution.majorityElement(v1), 3);

    vector<int> v2 = {2,2,1,1,1,2,2};
    EXPECT_EQ(solution.majorityElement(v2), 2);
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

