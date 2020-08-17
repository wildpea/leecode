#include <string>
#include <set>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "via_stl.h"

using namespace std;

class Solution
{
public:
    vector<int> minStep(set<int> w, int n)
    {
        for (auto iter = w.begin(); iter != w.end(); ++iter) {
            int diff = n - *iter;
            if (diff == 0) {
                return;
            } else if (diff > 0) {
                minStep(w, diff);
            }
        }
    }


};

TEST(test_Solution, test_1)
{
    //Solution solution;
    //EXPECT_EQ(solution.run("III"), 3);
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
    Solution solution;
    set<int> w = {1,5,11};
    vector<int> vt = solution.minStep(w, 15);
    VIA::ViaSTL::printC<int>(vt);

    //int32_t ret = RUN_ALL_TESTS();
    //LOG(INFO) << "ret:" << ret;
    //cout << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}

