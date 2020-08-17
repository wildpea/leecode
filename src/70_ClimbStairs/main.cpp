#include <string>
#include <set>
#include <map>
#include <vector>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
    	if (n == 1) return 1;
    	else if (n == 2) return 2;

    	int rst[n + 1];
    	rst[0] = 0;
    	rst[1] = 1;
    	rst[2] = 2;

    	for (int i = 3; i <= n; ++i)
    	{
    		rst[i] = rst[i - 1] + rst[i - 2];
    	}
    	return rst[n];
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.climbStairs(2), 2);
    EXPECT_EQ(solution.climbStairs(3), 3);
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

