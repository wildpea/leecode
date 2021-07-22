#include "via_util.h"

class Solution
{
public:
	int numWays(const int n) {
		int x = max(n, 3);
		int vs[x];
		vs[0] = 1;
		vs[1] = 1;
		vs[2] = 2;
		if (n <= 2) {
			return vs[n];
		}

		const int mod = 1000000007;
		for (int i = 3; i <= n; ++i) {
			vs[i] = vs[i-1] + vs[i-2];
			if (vs[i] >= mod) {
				vs[i] = vs[i] % mod;
			}
		}

		return vs[n];
	}
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.numWays(7), 21);
    EXPECT_EQ(solution.numWays(0), 1);
}
