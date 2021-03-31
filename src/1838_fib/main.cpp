#include "via_util.h"

class Solution
{
public:
    int fib(int n)
    {
    	if (n == 0) return 0;
    	if (n == 1) return 1;
    	uint64_t v[n + 1];
    	v[0] = 0;
    	v[1] = 1;

    	for (int i = 2; i <= n; ++i) {
    		v[i] = v[i-1] % 1000000007 + v[i-2] % 1000000007;
    	}
    	return v[n] % 1000000007;
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.fib(5), 5);
    EXPECT_EQ(solution.fib(20), 6765);
    EXPECT_EQ(solution.fib(46), 836311896);
    EXPECT_EQ(solution.fib(54), 267570670);
    EXPECT_EQ(solution.fib(76), 598991529);
//    EXPECT_EQ(solution.fib(100), 688011627);

    //1000000007
    //1836311903
}
