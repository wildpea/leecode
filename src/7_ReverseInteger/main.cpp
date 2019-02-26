#include <string>
#include <sstream>

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        if (x <= 0-std::pow(2,31) || x >= std::pow(2,31)-1) return 0;

        long rt = 0;

        std::stringstream ss;
        ss << abs(x);
        std::string str = ss.str();
        std::string str2;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            str2.append(&str.at(i),1);
        }
        rt = strtoul(str2.c_str(), NULL, 10);
        if (x < 0) rt = 0 - rt;

        if (rt <= 0-std::pow(2,31) || rt >= std::pow(2,31)-1) rt = 0;

        return rt;
    }
};


