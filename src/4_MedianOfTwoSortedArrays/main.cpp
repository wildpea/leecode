#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> num;

        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(num));
        std::sort(num.begin(), num.end());

        int len = num.size();
        int i = len / 2;
        int ODD = 1;

        //偶
        if ((len & ODD) == 0)
        {
            return double(num[i] + num[i - 1]) / 2;
        }
        else
        {
            return num[i];
        }
    }
};


