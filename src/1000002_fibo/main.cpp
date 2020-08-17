#include <string>
#include <set>
#include <map>
#include <vector>
#include <sys/time.h>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

uint64_t currentTime() {
	struct timeval tx;
	gettimeofday(&tx, NULL);
	return tx.tv_sec * 1000 + tx.tv_usec;
}

class Solution
{
public:
    int run(int n)
    {
    	if (n == 1) return 0;
    	if (n == 2) return 1;
    	return run(n-1) + run(n-2);
    }

    int run2(int n)
    {
    	if (n == 1) return 0;
    	if (n == 2) return 1;

    	int v[n];
    	v[0] = 0;
    	v[1] = 1;

    	int i = 1;
    	while (++i <= n) {
    		v[i] = v[i-1] + v[i-2];
    	}
    	return v[n - 1];
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    uint64_t l1 = currentTime();
    int r1 = solution.run(50);
    uint64_t l2 = currentTime();
    int r2 = solution.run2(50);
    uint64_t l3 = currentTime();
    cout << r1 << ", " << r2 << endl;
    cout << l1 << "< " << l2 << "< " << l3 << endl;
    cout << "run: " << l2 - l1 << ", run2: " << l3-l2 << endl;

    //EXPECT_EQ(solution.run(11), 55);
    //EXPECT_EQ(solution.run2(11), 55);
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

