#include "via_util.h"

class Solution
{
public:
	int maxValue(vector<vector<int>>& grid)
	{
		int x = grid.size();
		if (x == 0) return 0;
		int y = grid[0].size();
		if (y == 0) return 0;
		int rst[x][y];

		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				if (i == 0 && j == 0) {
					rst[i][j] = grid[i][j];
					continue;
				}
				if (i == 0) {
					rst[i][j] = grid[i][j] + rst[i][j-1];
					continue;
				}
				if (j == 0) {
					rst[i][j] = grid[i][j] + rst[i-1][j];
					continue;
				}
				rst[i][j] = grid[i][j] + max(rst[i-1][j], rst[i][j-1]);
			}
		}
		return rst[x-1][y-1];

	}
//    int maxValue(vector<vector<int>>& grid)
//    {
//    	int x = grid.size();
//    	if (x == 0) return 0;
//    	int y = grid[0].size();
//    	if (y == 0) return 0;
//
//    	int i = 0, j = 0;
//    	return maxValueInner(grid, i, j, x, y);
//    }
//
//    int maxValueInner(const vector<vector<int>> &grid, int i, int j, int x, int y) {
//    	if (i == x-1 && j == y-1) {
//    		return grid[i][j];
//    	}
//
//    	int a = 0, b = 0;
//    	if (i < x-1) {
//    		a = maxValueInner(grid, i + 1, j, x, y);
//    	}
//    	if (j < y-1) {
//    		b = maxValueInner(grid, i, j + 1, x, y);
//    	}
//    	return grid[i][j] + max(a, b);
//    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

//    vector<int> a1 = {1,3,1};
//    vector<int> a2 = {1,5,1};
//    vector<int> a3 = {4,2,1};
//    vector<int> a4 = {4,2,6};
//    vector<vector<int>> v2 = {a1, a2, a3, a4};
    vector<int> a1 = {5,0,1,1,2,1,0,1,3,6,3,0,7,3,3,3,1};
    vector<int> a2 = {1,4,1,8,5,5,5,6,8,7,0,4,3,9,9,6,0};
    vector<int> a3 = {2,8,3,3,1,6,1,4,9,0,9,2,3,3,3,8,4};
    vector<int> a4 = {3,5,1,9,3,0,8,3,4,3,4,6,9,6,8,9,9};
    vector<int> a5 = {3,0,7,4,6,6,4,6,8,8,9,3,8,3,9,3,4};
    vector<int> a6 = {8,8,6,8,3,3,1,7,9,3,3,9,2,4,3,5,1};
    vector<int> a7 = {7,1,0,4,7,8,4,6,4,2,1,3,7,8,3,5,4};
    vector<int> a8 = {3,0,9,6,7,8,9,2,0,4,6,3,9,7,2,0,7};
    vector<int> a9 = {8,0,8,2,6,4,4,0,9,3,8,4,0,4,7,0,4};
    vector<int> a10 = {3,7,4,5,9,4,9,7,9,8,7,4,0,4,2,0,4};
    vector<int> a11 = {5,9,0,1,9,1,5,9,5,5,3,4,6,9,8,5,6};
    vector<int> a12 = {5,7,2,4,4,4,2,1,8,4,8,0,5,4,7,4,7};
    vector<int> a13 = {9,5,8,6,4,4,3,9,8,1,1,8,7,7,3,6,9};
    vector<int> a14 = {7,2,3,1,6,3,6,6,6,3,2,3,9,9,4,4,8};
    vector<vector<int>> v2 = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14};
    EXPECT_EQ(solution.maxValue(v2), 12);
}
