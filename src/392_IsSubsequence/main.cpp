#include <string>
#include <set>
#include <map>
#include <vector>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    bool run(string s, string t)
    {
    	if (s.size() > t.size()) return false;

    	int t_cur = 0;
    	for (int i = 0, len = s.size(); i < len; ++i)
    	{
    		bool found = false;
    		for (int j = t_cur, len_j = t.size(); j < len_j; ++j)
    		{
    			if (s.at(i) == t.at(j)) {
    				found = true;
    				t_cur = j+1;
    				break;
    			}
    		}
    		if (!found)
    			return false;
    	}

    	return true;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.run("abc", "ahbgdc"), true);
    EXPECT_EQ(solution.run("acb", "ahbgdc"), false);
    EXPECT_EQ(solution.run("axc", "ahbgdc"), false);
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

