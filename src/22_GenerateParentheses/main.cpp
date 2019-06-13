#include <string>
#include <set>
#include <map>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include <limits>
#include "via_stl.h"

using namespace std;

const char PL = '(';
const char PR = ')';
class Solution
{
public:
    vector<char> vc_;
    int n_;
    vector<string> generateParenthesis(int n) {
        vector<string> rt;
        vc_.push_back(PL);
        vc_.push_back(PR);
        n_ = n;

        int left = 0, right = 0;
        string s = "";
        cout << "s: " << s << endl;
        add(rt, s, 2*n, left, right);

        return rt;
    }

    int add(vector<string> &rt, string &str, int len, int left, int right) {
        int ret = 0;
        string s;
        int l = 0, r = right;
        for (auto iter = vc_.begin(); iter != vc_.end(); ++iter) {
            s = str;
            l = left;
            r = right;
            cout << "--------in new for now!--------" << *iter << ", len: " << len << endl;
            ret = addItem(s, *iter, len, l, r);
            if (ret == 0) {
                cout << "s : " << s << ", in == 0 , invoke add" << endl;
                add(rt, s, len - 1, l, r);
            } else if (ret == 1) {
                cout << "add!!! s : " << s << ", in == 1, found one!" << endl;
                rt.push_back(s);
            } else {
                cout << "s : " << s << ", in else, not found, and continue" << endl;
            }

            if (len == 0) break;
        }
        return ret;
    }

    int addItem(string &str, char item, int len, int &left, int &right) {
        if (len == 0) {
            cout << "in == 1" << endl;
            return 1; //ok了
        }
        if (item == PL) ++left;
        if (item == PR) ++right;
        if (left < right || left > n_) {
            cout << "in == -1" << ", left: " << left << ", right: " << right << endl;
            return -1;    //失败
        }

        str = item == PL ? str + PL : str + PR;
        cout << "str: " << str << ", left: " << left << ", right: " << right << endl;
        return 0;   //继续跑
    }

};

TEST(test_Solution, test_1)
{
    Solution solution;
    vector<string> rt = solution.generateParenthesis(1);
    //vector<string> rt = solution.generateParenthesis(2);
    //vector<string> rt = solution.generateParenthesis(3);

    cout << "--------" << endl;
    for (auto it : rt) {
        cout << it << endl;
    }
//    vector<string> v = {"((()))",
//                        "(()())",
//                        "(())()",
//                        "()(())",
//                        "()()()"};

    //EXPECT_EQ(solution.generateParenthesis(3), v);
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
    //vector<string> rt = solution.generateParenthesis(1);
    //vector<string> rt = solution.generateParenthesis(2);
    vector<string> rt = solution.generateParenthesis(3);

    cout << "--------" << endl;
    ViaSTL::print_c<string>(rt);

    //int32_t ret = RUN_ALL_TESTS();
//    LOG(INFO) << "ret:" << ret;
    //cout << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}

