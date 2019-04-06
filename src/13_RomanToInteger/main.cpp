#include <string>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

/**
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
**/
class Solution
{
public:
    int romanToInt(string s) {
    {
        return 0;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.romanToInt("III"), 3);
    EXPECT_EQ(solution.romanToInt("IV"), 4);
    EXPECT_EQ(solution.romanToInt("IX"), 9);
    EXPECT_EQ(solution.romanToInt("LVIII"), 58);
    EXPECT_EQ(solution.romanToInt("LX"), 60);
    EXPECT_EQ(solution.romanToInt("CI"), 101);
    EXPECT_EQ(solution.romanToInt("MCMXCIV"), 1994);
    EXPECT_EQ(solution.romanToInt("MMMCMXCIX"), 3999);
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
    LOG(INFO) << "ret:" << ret;

    google::ShutdownGoogleLogging();
    return 0;
}
