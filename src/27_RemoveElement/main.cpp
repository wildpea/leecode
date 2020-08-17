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
    int removeElement(vector<int>& nums, int val) {
        for (auto iter = nums.begin(); iter != nums.end(); ) {
            if (*iter == val) {
                iter = nums.erase(iter);
            } else
            {
                ++iter;
            }
        }
        return nums.size();
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<int> v1 = {1,2,3,3,4};
    EXPECT_EQ(solution.removeElement(v1,3), 3);
    EXPECT_EQ(solution.removeElement(v1,1), 2);
    EXPECT_EQ(solution.removeElement(v1,6), 2);

    vector<int> v2 = {};
    EXPECT_EQ(solution.removeElement(v2,6), 0);
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

