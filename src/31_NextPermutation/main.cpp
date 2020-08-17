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
    void nextPermutation(vector<int>& nums) {
        int total = nums.size();
        if (total == 0)
            return;
        int m_num = nums[total - 1];
        for (int i = total-2; i >= 0; --i) {
            if (nums[i] < m_num) {
                sort(nums.begin() + i + 1, nums.end());
                for (int j = i + 1; j < total; ++j) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
                return;
            }
            m_num = nums[i];
        }
        sort(nums.begin(), nums.end());
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<int> n1 = {1,2,3,4,5};
    solution.nextPermutation(n1);
    vector<int> n11 = {1,2,3,5,4};
    EXPECT_EQ(n1, n11);

    vector<int> n2 = {1,1,5};
    solution.nextPermutation(n2);
    vector<int> n22 = {1,5,1};
    EXPECT_EQ(n2, n22);

    vector<int> n3 = {3,2,1};
    solution.nextPermutation(n3);
    vector<int> n33 = {1,2,3};
    EXPECT_EQ(n3, n33);

    vector<int> n4 = {1,2,3};
    solution.nextPermutation(n4);
    vector<int> n44 = {1,3,2};
    EXPECT_EQ(n4, n44);

    vector<int> n5 = {1,3,2};
    solution.nextPermutation(n5);
    vector<int> n55 = {2,1,3};
    EXPECT_EQ(n5, n55);

    vector<int> n6 = {2,1,3};
    solution.nextPermutation(n6);
    vector<int> n66 = {2,3,1};
    EXPECT_EQ(n6, n66);

    vector<int> n7 = {3,1,2};
    solution.nextPermutation(n7);
    vector<int> n77 = {3,2,1};
    EXPECT_EQ(n7, n77);

    vector<int> n8 = {3,2,1,4};
    solution.nextPermutation(n8);
    vector<int> n88 = {3,2,4,1};
    EXPECT_EQ(n8, n88);

    vector<int> n9 = {2,3,1};
    solution.nextPermutation(n9);
    vector<int> n99 = {3,1,2};
    EXPECT_EQ(n9, n99);
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

