#include <string>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (!checkS(s) || !checkP(p)) return false;

        for (int32_t i = 0, len = s.length(); i < len; ++i)
        {
            char *s_start = &s.at(i), *s_c = s_start;
            char *p_start = &p.at(0), *p_c = p_start;
            while (*p_c != '\0' &&  *p_c != '\0')
            {
                LOG(INFO) << "s_c " << *s_c << "\tp_c " << *p_c;

                if (*s_c != *p_c && *p_c != '.')
                {
                    break;
                }

                ++s_c;
                ++p_c;
            }

            if (*p_c == '\0')
                return true;
        }

        return false;
    }

    bool checkS(string &s)
    {
        if (s.empty()) return false;
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            char c = s.at(i);
            if (c < 'a' || c > 'z')
            {
                cout << c << endl;
                return false;
            }
        }
        return true;
    }

    bool checkP(string &s)
    {
        if (s.empty()) return false;
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            char c = s.at(i);
            if ((c < 'a' || c > 'z') && c != '*' && c != '.')
            {
                cout << c << endl;
                return false;
            }
        }
        return true;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.isMatch("abcd", "a"), true);
    EXPECT_EQ(solution.isMatch("abcd", "ab"), true);
    EXPECT_EQ(solution.isMatch("abcd", "ac"), false);
    EXPECT_EQ(solution.isMatch("abcd", "bc"), true);
    EXPECT_EQ(solution.isMatch("abcd", "a."), true);
    EXPECT_EQ(solution.isMatch("abcd", ".b"), true);
    EXPECT_EQ(solution.isMatch("abcd", "z."), false);
    EXPECT_EQ(solution.isMatch("abcd", ".*"), true);
//    EXPECT_EQ(solution.isMatch("abcd", "a.*"), true);
//    EXPECT_EQ(solution.isMatch("abcd", "ac.*"), false);
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
