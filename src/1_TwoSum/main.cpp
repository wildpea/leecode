#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> rt;
        for (int i = 0, len = nums.size(); i < len - 1; ++i)
        {
            int x = nums[i];
            for (int j = i + 1; j < len; ++j)
            {
                if (x + nums[j] == target)
                {
                    rt.push_back(i);
                    rt.push_back(j);
                    return rt;
                }
            }
        }
        return rt;
    }
};


