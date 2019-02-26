#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (!checkS(s) || !checkP(p)) return false;

        //for ()

        return true;
    }

    bool checkS(string &s)
    {
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            if (s.at(i) < 'a' || s.at(i) > 'z')
                return false;
        }
        return true;
    }

    bool checkP(string &s)
    {
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            char c = s.at(i);
            if ((c < 'a' || c > 'z') && c != '*' && c != '.')
                return false;
        }
        return true;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.isMatch("abcd", "a"), true);
    EXPECT_EQ(solution.isMatch("abcd", "ab"), true);
    EXPECT_EQ(solution.isMatch("abcd", "ac"), false);
//    EXPECT_EQ(solution.isMatch("abcd", ".*"), true);
//    EXPECT_EQ(solution.isMatch("abcd", "a.*"), true);
//    EXPECT_EQ(solution.isMatch("abcd", "ac.*"), false);
}

int32_t main(int32_t argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
