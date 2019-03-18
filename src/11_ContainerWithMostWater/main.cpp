#include <string>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int rt = 0;
        for (int i = 0, len = height.size(); i < len - 1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                int tmp = min(height[i], height[j]) * (j - i);
                if (tmp > rt)
                    rt = tmp;
            }
        }
        return rt;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<int> v1 = {1,8,6,2,5,4,8,3,7};
    EXPECT_EQ(solution.maxArea(v1), 49);
}

DEFINE_string(cmd, "", "cmd");
DEFINE_string(logdir, "./log", "logdir");


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
