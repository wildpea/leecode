#include <string>
#include <set>
#include <map>
#include <limits>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor) {
        bool plus = (dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? true : false;
        int i = 0;
        int n = dividend;
        int x = divisor;

        if (mabs(n) < 0 || mabs(x) < 0) {
            return plus ? numeric_limits<int>::max() : numeric_limits<int>::min();
        }

        while (n > x) {
            n -= x;
            ++i;
        }
        return plus ? i : 0 - i;
    }

    int mabs(int &num) {
        long x = abs(long(num));
        if (x > numeric_limits<int>::max()) {
            return -1;
        }

        num = (int)x;
        return 0;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.divide(10, 3), 3);
    EXPECT_EQ(solution.divide(7, -3), -2);
    EXPECT_EQ(solution.divide(-7, -3), 2);
    EXPECT_EQ(solution.divide(-2147483648, -1), 2);
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

