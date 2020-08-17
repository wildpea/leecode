#include <string>
#include <set>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    bool compare(const char *p1, const char *p2) {
        while (*p2 != '\0') {
            if (p1 == NULL) return false;
            if (*p1 != *p2) return false;
            ++p1;
            ++p2;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        const char *st = haystack.c_str();
        const char *n = needle.c_str();
        for (int i = 0, len = haystack.size(); i <len; ++i)
        {
            st = &haystack.at(i);
            if (compare(st, n))
                return i;
        }
        return -1;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.strStr("hello", "ll"), 2);
    EXPECT_EQ(solution.strStr("aa", ""), 0);
    EXPECT_EQ(solution.strStr("", ""), 0);
    EXPECT_EQ(solution.strStr("hello", "h"), 0);
    EXPECT_EQ(solution.strStr("hello", "ee"), -1);
    EXPECT_EQ(solution.strStr("hello", "wildpea"), -1);
    EXPECT_EQ(solution.strStr("", "wildpea"), -1);
    EXPECT_EQ(solution.strStr("mississippi", "issip"), 4);
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

