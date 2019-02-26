#include <string>
#include <map>

class Solution {
public:
    int myAtoi(std::string str) {
        int len = str.size();
        if (len == 0) return 0;

        std::map<char, int> mi;
        mi.insert(std::make_pair('0', 0));
        mi.insert(std::make_pair('1', 1));
        mi.insert(std::make_pair('2', 2));
        mi.insert(std::make_pair('3', 3));
        mi.insert(std::make_pair('4', 4));
        mi.insert(std::make_pair('5', 5));
        mi.insert(std::make_pair('6', 6));
        mi.insert(std::make_pair('7', 7));
        mi.insert(std::make_pair('8', 8));
        mi.insert(std::make_pair('9', 9));

        long rt = 0;

        trim(str);

        len = str.size();
        if (len == 0) return 0;

        int i = 0;
        bool ng = false;
        char c = str.at(0);
        if (c == '-')
        {
            ng = true;
            ++i;
        }
        else if (c == '+')
        {
            ++i;
        }

        std::map<char, int>::iterator iter;

        while (i < len && (iter = mi.find(str.at(i))) != mi.end())
        {
            rt = rt * 10 + iter->second;
            if (rt >= INT_MAX) break;
            ++i;
        }

        if (ng && i > 0)
        {
            rt = 0 - rt;
            if (rt <= INT_MIN) rt = INT_MIN;
        }
        else if (rt >= INT_MAX)
        {
            rt = INT_MAX;
        }
        return rt;
    }

    void trim(std::string &str)
    {
        int id = str.find_first_not_of(" ");
        if (id != 0 && id != std::string::npos)
        {
            str = str.substr(id);
        }
    }
};


