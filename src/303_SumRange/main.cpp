#include <string>
#include <set>
#include <map>
#include <vector>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class NumArray
{
public:
	vector<int> rst;
	NumArray(vector<int>& nums) {
		int len = nums.size();
		rst.push_back(nums[0]);
		for (int i = 1; i < len; ++i)
		{
			rst.push_back(nums[i] + rst[i-1]);
		}

	}

    int sumRange(int i, int j)
    {
    	if (i == 0) return rst[j];
    	else return rst[j] - rst[i -1];
    }
};

TEST(test_Solution, test_1)
{
	vector<int> v1 = {-2, 0, 3, -5, 2, -1};
	NumArray solution(v1);

    EXPECT_EQ(solution.sumRange(0, 2), 1);
    EXPECT_EQ(solution.sumRange(2, 5), -1);
    EXPECT_EQ(solution.sumRange(0, 5), -3);
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

