#include <string>
#include <list>
#include <sstream>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int max_i1 = 0;
        int j = 0;

        int len = s.size();
        for (int i = 0; i< len; ++i) {
        	int i1 = getLen(s, len, i, i);
        	int i2 = getLen(s, len, i, i+1);
        	int ii = max(i1, i2);
        	if (ii > max_i1) {
        		//cout << "ii > max_id: " << ii << "," << max_i1 << endl;
        		max_i1 = ii;
        		j = max_i1 & 1 ? i : i+1;
        		//cout << "j: " << j << endl;
        	}
        }
        bool g = max_i1 & 1;
        int start = g ? j - (max_i1 - 1) / 2 : j - max_i1 / 2;
        //cout << "max_i1: " << max_i1 << ", g:  " << g << ", start: " << start << endl;

        return s.substr(start, max_i1);
    }

    int getLen(string s, int len, int i1, int i2) {
    	while (i1 >= 0 && i2 < len) {
    		if (s.at(i1) != s.at(i2)) {
    			break;
    		}
    		--i1;
    		++i2;
    	}
    	return i2 - i1 - 1;
    }
};


TEST(test_Solution, test_1)
{
    Solution solution;
    EXPECT_EQ(solution.longestPalindrome("haha"), "hah");
    EXPECT_EQ(solution.longestPalindrome("hahah"), "hahah");
    EXPECT_EQ(solution.longestPalindrome("bb"), "bb");
    EXPECT_EQ(solution.longestPalindrome("b"), "b");
    EXPECT_EQ(solution.longestPalindrome("haha"), "hah");
    EXPECT_EQ(solution.longestPalindrome("baha"), "aha");

    string s = solution.longestPalindrome("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");
    EXPECT_EQ(s, "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");

}

DEFINE_string(cmd, "", "cmd");
DEFINE_string(logdir, "./", "logdir");


int32_t main(int32_t argc, char **argv)
{
    gflags::ParseCommandLineFlags(&argc, &argv, false);
    testing::InitGoogleTest(&argc, argv);
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = FLAGS_logdir;

    //LOG(INFO) << FLAGS_cmd;

    int32_t ret = RUN_ALL_TESTS();
    //LOG(INFO) << "ret:" << ret;
    cout << ret << endl;

    google::ShutdownGoogleLogging();
    return 0;
}



//class Solution {
//public:
//    std::string longestPalindrome(std::string s) {
//        if (s.size() == 0) return "";
//
//        std::string max_s;
//        std::string target;
//        std::list<char> lc;
//
//        int x = 0, y = 0;
//        char c_index, c_x, c_y;
//
//        for (int index = 0, len = s.size(); index < len; ++index)
//        {
//            lc.clear();
//
//            c_index = s.at(index);
//            lc.push_back(c_index);
//
//            x = y = index;
//
//            {
//                --x;
//                ++y;
//                while (true)
//                {
//                    if (x >= 0 && s.at(x) == c_index)
//                    {
//                        lc.push_front(s.at(x));
//                        --x;
//                    }
//                    else if (y < s.size() && s.at(y) == c_index)
//                    {
//                        lc.push_front(s.at(y));
//                        ++y;
//                    }
//                    else
//                    {
//                        break;
//                    }
//                }
//
//                while (true)
//                {
//                    if (x < 0 || y >= s.size()) break;
//
//                    c_x = s.at(x);
//                    c_y = s.at(y);
//
//                    if (c_x != c_y) break;
//
//                    lc.push_front(c_x);
//                    lc.push_back(c_y);
//
//                    --x;
//                    ++y;
//                }
//            }
//
//            target = type2str(lc);
//            if (target.size() > max_s.size())
//                max_s = target;
//        }
//        return max_s;
//    }
//
//private:
//    std::string type2str(std::list<char> &lc)
//    {
//        std::stringstream ss;
//        for (auto iter = lc.begin(); iter != lc.end(); ++iter)
//            ss << *iter;
//        return ss.str();
//    }
//};
