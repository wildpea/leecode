#include "via_util.h"

class Solution
{
public:
	vector<string> permutation(string s) {

	}
};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<string> ss = solution.permutation("abc");
    printS(ss);
    //EXPECT_EQ(solution.run("abc"), 3);
}
