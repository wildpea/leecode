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
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rt;
        vector<int> v('9' + 1);
        for (auto iter1 = board.begin(); iter1 != board.end(); ++iter1) {
            for (auto iter = iter1->begin(); iter != iter1->end(); ++iter) {

            }
        }
        return rt;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;
    vector<char> v1 = {"5","3",".",".","7",".",".",".","."};
    vector<char> v2 = {"6",".",".","1","9","5",".",".","."};
    vector<char> v3 = {".","9","8",".",".",".",".","6","."};
    vector<char> v4 = {"8",".",".",".","6",".",".",".","3"};
    vector<char> v5 = {"4",".",".","8",".","3",".",".","1"};
    vector<char> v6 = {"7",".",".",".","2",".",".",".","6"};
    vector<char> v7 = {".","6",".",".",".",".","2","8","."};
    vector<char> v8 = {".",".",".","4","1","9",".",".","5"};
    vector<char> v9 = {".",".",".",".","8",".",".","7","9"};
    vector<vector<char>> v1111 = {v1,v2,v3,v4,v5,v6,v7,v8,v9};

    EXPECT_EQ(solution.isValidSudoku(v1111), true);


    vector<char> v21 = {"8","3",".",".","7",".",".",".","."};
    vector<char> v22 = {"6",".",".","1","9","5",".",".","."};
    vector<char> v23 = {".","9","8",".",".",".",".","6","."};
    vector<char> v24 = {"8",".",".",".","6",".",".",".","3"};
    vector<char> v25 = {"4",".",".","8",".","3",".",".","1"};
    vector<char> v26 = {"7",".",".",".","2",".",".",".","6"};
    vector<char> v27 = {".","6",".",".",".",".","2","8","."};
    vector<char> v28 = {".",".",".","4","1","9",".",".","5"};
    vector<char> v29 = {".",".",".",".","8",".",".","7","9"};
    vector<vector<char>> v2222 = {v21,v22,v23,v24,v25,v26,v27,v28,v29};
    EXPECT_EQ(solution.isValidSudoku(v1111), false);

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

