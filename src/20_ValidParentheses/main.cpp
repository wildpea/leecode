#include <string>
#include <stack>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

/**
 * '(', ')', '{', '}', '[' and ']'
 */

#define RETURN(rt) \
{ \
    LOG(INFO) << "."; \
    return rt; \
}

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty()) return true;
        int len = s.size();
        if ((len & 0x1) != 0) return false;
        int max = len / 2;
        map<char, char> mp;
        mp.insert(make_pair('(', ')'));
        mp.insert(make_pair('{', '}'));
        mp.insert(make_pair('[', ']'));
        stack<char> st;
        int i = 0;
        while (i < len){
            char c =  s.at(i);
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (c == ')' || c == '}' || c == ']'){
                if (st.size() == 0) return false;
                char g = st.top();
                st.pop();
                auto p = mp.find(g);
                if (p == mp.end()) return false;
                if (p->second != c) return false;
            } else {
                return false;
            }
            if (st.size() > max) return false;

            ++i;
        }

        return st.size() == 0 ? true : false;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.isValid("()"), true);
    EXPECT_EQ(solution.isValid("()[]{}"), true);
    EXPECT_EQ(solution.isValid("(]"), false);
    EXPECT_EQ(solution.isValid("([)]"), false);
    EXPECT_EQ(solution.isValid("{[]}"), true);
    EXPECT_EQ(solution.isValid("){"), false);
    EXPECT_EQ(solution.isValid("{[x]}"), false);
    EXPECT_EQ(solution.isValid(""), true);
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

    cout << "before:" << endl;
    int32_t ret = RUN_ALL_TESTS();
    cout << "ret:" << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}

