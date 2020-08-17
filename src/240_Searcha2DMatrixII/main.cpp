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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int a = 0, x = 0, y = 0;

        while (m != 0 && n != 0) {
            a = min(m,n);
            cout << "m: " << m << ", n: " << n << ", a: " << a << " , x: " << x << ", y: " << y <<endl;
            for (int i = 0; i < a; ++i)
            {
                if (matrix[i+x][i+y] == target) return true;
                if (matrix[i+x][i+y] > target) {
                    if (find(matrix[i+x].begin(), matrix[i+x].begin() + i, target) != matrix[i+x].begin() + i) return true;
                    for (int j = 0; j < i; ++j)
                        if (matrix[j+x][i+y] == target) return true;
                }
            }
            if (m > n) {
                x += n;
                m -= n;
            } else {
                y += m;
                if (m == n) m -= m;
                n -= m;
            }
        }

        return false;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<vector<int>> vc;

    vector<int> v1 = {1,   4,  7, 11, 15, 17};
    vector<int> v2 = {2,   5,  8, 12, 19, 21};
    vector<int> v3 = {3,   6,  9, 16, 22, 25};
    vector<int> v5 = {10, 13, 14, 17, 24, 27};
    vector<int> v6 = {18, 21, 23, 26, 30, 31};
    vc.push_back(v1);
    vc.push_back(v2);
    vc.push_back(v3);
    vc.push_back(v5);
    vc.push_back(v6);

    EXPECT_EQ(solution.searchMatrix(vc, 5), true);
    EXPECT_EQ(solution.searchMatrix(vc, 11), true);
    EXPECT_EQ(solution.searchMatrix(vc, 6), true);
    EXPECT_EQ(solution.searchMatrix(vc, 25), true);
    EXPECT_EQ(solution.searchMatrix(vc, 20), false);
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

