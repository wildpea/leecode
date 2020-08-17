#include <string>
#include <set>
#include <map>
#include <vector>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

/**
 * 操作：
 * 选出任一 x，满足 0 < x < N 且 N % x == 0 。
 * 用 N - x 替换黑板上的数字 N
 * 如果玩家无法执行这些操作，就会输掉游戏
 * 爱丽丝先手开局，爱丽丝在游戏中取得胜利时才返回 True，否则返回 false
 * 1 <= N <= 1000
 */
class Solution
{
public:
    bool run(int n)
    {
    	if (n == 1) return false;
    	if (n == 2) return true;
    	bool rt[n + 1];
    	rt[1] = false;
    	rt[2] = true;

    	for (int i = 3; i <= n; ++i) {
    		bool found = false;
    		for (int j = 0; j < i; ++j) {
    			if (n % j == 0 && rt[j]) {
    				rt[i] = true;
    				found = true;
    				break;
    			}
    		}
    		if (!found) rt[i] = false;
    	}

    	return rt[n];
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.run(2), true);
    EXPECT_EQ(solution.run(3), false);
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

