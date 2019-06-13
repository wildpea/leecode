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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int last_value;
        bool init = false;
        auto iter = nums.begin();
        vector<int> rt;
        while (iter != nums.end())
        {
            if (!init) {
                init = true;
                last_value = *iter;
                rt.push_back(last_value);
            } else if (*iter != last_value) {
                last_value = *iter;
                rt.push_back(last_value);
            }
            ++iter;
        }
        nums = rt;
        return nums.size();
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<int> vt = {0,0,1,1,1,2,2,3,3,4};
    EXPECT_EQ(solution.removeDuplicates(vt), 5);
    ViaSTL::print_c<int>(vt);
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

