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
        int a = 0, x = m-1, y = 0;

        while (x >= 0 && y <= n-1) {
        	int c = matrix[x][y];
        	cout << x << "," << y << "," << c << endl;
        	if (c == target) {
        		return true;
        	}
        	if (c > target) {
				x--;
			} else if (y != n-1) {
        		if (matrix[x][y+1] > target) {
        			x--;
        			continue;
        		} else {
        			y++;
        		}
        	} else {
        		return false;
        	}
        }

        return false;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;


    vector<int> v1 = {1,   4,  7, 11, 15, 17};
    vector<int> v2 = {2,   5,  8, 12, 19, 21};
    vector<int> v3 = {3,   6,  9, 16, 22, 25};
    vector<int> v4 = {10, 13, 14, 17, 24, 27};
    vector<int> v5 = {18, 21, 23, 26, 30, 31};
    vector<vector<int>> vc = {v1, v2, v3, v4, v5};


    EXPECT_EQ(solution.searchMatrix(vc, 5), true);
    EXPECT_EQ(solution.searchMatrix(vc, 11), true);
    EXPECT_EQ(solution.searchMatrix(vc, 6), true);
    EXPECT_EQ(solution.searchMatrix(vc, 25), true);
    EXPECT_EQ(solution.searchMatrix(vc, 20), false);


//	vector<int> v1 = {5};
//    vector<int> v2 = {6};
//    vector<vector<int>> vc = {v1, v2};
//
//    EXPECT_EQ(solution.searchMatrix(vc, 5), true);
//    EXPECT_EQ(solution.searchMatrix(vc, 11), false);
//    EXPECT_EQ(solution.searchMatrix(vc, 6), true);
//    EXPECT_EQ(solution.searchMatrix(vc, 25), false);
//    EXPECT_EQ(solution.searchMatrix(vc, 20), false);
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

