#include <string>
#include <list>
#include <sstream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() == 0) return "";

        std::string max_s;
        std::string target;
        std::list<char> lc;

        int x = 0, y = 0;
        char c_index, c_x, c_y;

        for (int index = 0, len = s.size(); index < len; ++index)
        {
            lc.clear();

            c_index = s.at(index);
            lc.push_back(c_index);

            x = y = index;

            {
                --x;
                ++y;
                while (true)
                {
                    if (x >= 0 && s.at(x) == c_index)
                    {
                        lc.push_front(s.at(x));
                        --x;
                    }
                    else if (y < s.size() && s.at(y) == c_index)
                    {
                        lc.push_front(s.at(y));
                        ++y;
                    }
                    else
                    {
                        break;
                    }
                }

                while (true)
                {
                    if (x < 0 || y >= s.size()) break;

                    c_x = s.at(x);
                    c_y = s.at(y);

                    if (c_x != c_y) break;

                    lc.push_front(c_x);
                    lc.push_back(c_y);

                    --x;
                    ++y;
                }
            }

            target = type2str(lc);
            if (target.size() > max_s.size())
                max_s = target;
        }
        return max_s;
    }

private:
    std::string type2str(std::list<char> &lc)
    {
        std::stringstream ss;
        for (auto iter = lc.begin(); iter != lc.end(); ++iter)
            ss << *iter;
        return ss.str();
    }
};


