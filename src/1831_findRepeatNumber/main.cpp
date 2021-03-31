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
	int findRepeatNumber(vector<int>& nums) {
		int len = nums.size();
		int x[len];
		memset(x, 0, sizeof(x));
		for (int i = 0; i < len; ++i) {
			int n = nums[i];
			if (x[n] == 0) x[n] = 1;
			else return n;
		}
		return 0;
	}
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<int> nums = {2, 3, 1, 0, 2, 5, 4};
    EXPECT_EQ(solution.findRepeatNumber(nums), 2);
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

