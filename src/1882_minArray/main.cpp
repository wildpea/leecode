#include "via_util.h"

class Solution
{
public:
    int minArray(vector<int>& numbers) {
    	if (numbers.size() == 0) {return 0;}
    	if (numbers.size() == 1) {return numbers[0];}

    	int len = numbers.size();
    	int left = 0, right = len - 1;
    	while (left < right) {
    		int mid = (right-left) / 2;
    		if (check(numbers, len, mid)) {
    			return numbers[mid];
    		}
    	}
    	return numbers[left];
    }

    int check(vector<int> &numbers, int len, int i) {
    	int left = i-1, right = i+1;
    	if (left <0) {left = len;}
    	if (right == len) {right = 0;}
    	return numbers[i] < numbers[left] && numbers[i] < numbers[right];
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;
    vector<int> v = {3,4,5,1,2};
    EXPECT_EQ(solution.minArray(v), 1);

//    vector<int> v1 ={2,2,2,0,1};
//    EXPECT_EQ(solution.minArray(v1), 0);
}
