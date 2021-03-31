#include "via_util.h"

class Solution
{
public:
    int run()
    {

    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.run("III"), 3);
}
