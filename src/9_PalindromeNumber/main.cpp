#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x %10 == 0 && x != 0)) return false;

        int revert_num = 0;
        while (x > revert_num)
        {
            revert_num = revert_num * 10 + x %10;
            x = x / 10;
        }

        return revert_num == x || revert_num / 10 == x;
    }

    bool isPalindrome_2(int x)
    {
        if (x < 0) return false;
        if (x < 10) return true;

        std::vector<int> vec;
        while (x > 0)
        {
            vec.push_back(x%10);
            x = x / 10;
        }

        for (auto iter = vec.begin(), iter2 = vec.end() - 1; iter != iter2 && iter != vec.end(); ++iter, --iter2)
        {
            if (*iter != *iter2) return false;
        }

        return true;

    }
};


