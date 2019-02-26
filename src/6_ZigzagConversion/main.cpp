#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1) return s;

        std::string str;
        int n = numRows + (numRows - 2);
        std::vector<std::vector<char>> vec;
        for (int32_t i = 0; i < numRows; ++i)
        {
            std::vector<char> v;
            vec.push_back(v);
        }

        for (int i = 0, len = s.size(); i < len; ++i)
        {
            int index = i % n;
            if (index >= numRows)
                index = n - index;

            vec[index].push_back(s.at(i));
        }

        std::stringstream ss;
        for (auto iter_i = vec.begin(); iter_i != vec.end(); ++iter_i)
            for (auto iter_j = iter_i->begin(); iter_j != iter_i->end(); ++iter_j)
                ss << *iter_j;

        return ss.str();
    }
};


