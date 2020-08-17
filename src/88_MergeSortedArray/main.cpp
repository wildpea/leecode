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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    }
};

TEST(test_Solution, test_1)
{
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

    vector<int> v1 = {1,2,3,0,0,0};
    vector<int> v2 = {2,5,6};
    vector<int> v3 = {1,2,2,3,5,6};
    solution.merge(v1, 3, v2, 3);
    VIA::ViaSTL::printC<int>(v1);
    //int32_t ret = RUN_ALL_TESTS();
    //LOG(INFO) << "ret:" << ret;
    //cout << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}

