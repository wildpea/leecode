#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        stringstream ss;
        char c = '\0';
        int i = 0;
        bool equl;
        char r;
        do
        {
            equl = true;
            for (auto iter = strs.begin(); iter != strs.end(); ++iter)
            {
                if (iter->size() < i+1)
                {
                    equl = false;
                    break;
                }
                r = iter->at(i);
                if (iter == strs.begin()) c = r;
                else
                {
                    if (r != c)
                    {
                        equl = false;
                        break;
                    }
                }
            }

            if (!equl) break;

            ss << c;
            ++i;

        } while (true);

        return ss.str();
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<string> v1 = {"flower","flow","flight"};
    EXPECT_EQ(solution.longestCommonPrefix(v1), "fl");

    vector<string> v2 = {"dog","racecar","car"};
    EXPECT_EQ(solution.longestCommonPrefix(v2), "");
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
