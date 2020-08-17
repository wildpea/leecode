#include <string>
#include <set>
#include <vector>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
    	int rt = 0;
    	for (auto iter = prices.begin(); iter != prices.end(); ++iter) {
    		for (auto iter2 = iter+1; iter2 != prices.end(); ++iter2) {
    			rt = max(rt, *iter2 - *iter);
    		}
    	}
    	return rt;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<int> v1 = {7,1,5,3,6,4};
    EXPECT_EQ(solution.maxProfit(v1), 5);

    vector<int> v2 = {7,6,5,4,3,2};
    EXPECT_EQ(solution.maxProfit(v2), 0);
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

