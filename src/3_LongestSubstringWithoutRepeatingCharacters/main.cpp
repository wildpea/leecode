#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() == 0) return 0;

        int max_len = 0, cur_len = 0, l_index = 0;
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            char c = s.at(i);

            int r = s.find_first_of(c, l_index);
            if (r == i)
            {
                ++cur_len;
            }
            else
            {
                max_len = std::max(max_len, cur_len);
                l_index = r+1;
                cur_len = i-r;
            }
        }

        return std::max(max_len, cur_len);
    }
};


