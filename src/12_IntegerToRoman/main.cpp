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
    string intToRoman(int num)
    {
        vector<char> symbol = {'I', 'V', 'X', 'L', 'C', 'D', 'M', '\0', '\0'};
        string str;
        int left = 0;
        int i = 0;
        do
        {
            left = num % 10;
            num = num / 10;

            if (left != 0)
            {
                getNum(left, symbol[i], symbol[i+1], symbol[i+2], str);
            }

            i += 2;
        }
        while(num != 0);
        return str;
    }

    void getNum(uint32_t n, char ls, char ms, char rs, string &target)
    {
        string str;
        if (n <= 3)
        {
            for (uint32_t i = 1; i <= n; ++i)
            {
                str += ls;
            }
        }
        else if (n == 4)
        {
            str = ls;
            str += ms;
        }
        else if (n < 9)
        {
            str = ms;
            for (uint32_t i = 6; i <= n; ++i)
            {
                str += ls;
            }
        }
        else if (n == 9)
        {
            str = ls;
            str += rs;
        }
        target = str + target;
        return;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.intToRoman(3), "III");
    EXPECT_EQ(solution.intToRoman(4), "IV");
    EXPECT_EQ(solution.intToRoman(9), "IX");
    EXPECT_EQ(solution.intToRoman(58), "LVIII");
    EXPECT_EQ(solution.intToRoman(60), "LX");
    EXPECT_EQ(solution.intToRoman(101), "CI");
    EXPECT_EQ(solution.intToRoman(1994), "MCMXCIV");
    EXPECT_EQ(solution.intToRoman(3999), "MMMCMXCIX");
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
