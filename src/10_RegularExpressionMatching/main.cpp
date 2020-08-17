#include <string>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (s.empty()) return p.empty();

        bool match = s.at(0) == p.at(0) || p.at(0) == '.';

        if (p.size() > 1 && p.at(1) == '*') {
        	return (match && isMatch(s.substr(0), p))
        			|| (isMatch(s, p.substr(2)));
        } else {
        	return match && isMatch(s.substr(0), p.substr(0));
        }
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

    EXPECT_EQ(solution.isMatch("aaa", "aa*a"), true);
    EXPECT_EQ(solution.isMatch("adb", "ac*db"), false);
    EXPECT_EQ(solution.isMatch("aaaaaaaab", "aa*ab"), true);
    EXPECT_EQ(solution.isMatch("asdfadsfasdfb", "a.*b"), true);
    EXPECT_EQ(solution.isMatch("asdfadsfasdfb", "a.*c"), false);
    EXPECT_EQ(solution.isMatch("asdfadsfasdfb", "a.*d.*b"), true);
    EXPECT_EQ(solution.isMatch("aa", "a*"), true);
    EXPECT_EQ(solution.isMatch("abcd", "a"), false);
    EXPECT_EQ(solution.isMatch("abcd", "ab"), false);
    EXPECT_EQ(solution.isMatch("abcd", "ac"), false);
    EXPECT_EQ(solution.isMatch("abcd", "bc"), false);
    EXPECT_EQ(solution.isMatch("abcd", "a.*"), true);
    EXPECT_EQ(solution.isMatch("abcd", ".b"), false);
    EXPECT_EQ(solution.isMatch("abcd", "z."), false);
    EXPECT_EQ(solution.isMatch("abcd", ".*"), true);
    EXPECT_EQ(solution.isMatch("ab", "ab"), true);
    EXPECT_EQ(solution.isMatch("aa", "a"), false);
    EXPECT_EQ(solution.isMatch("aab", "c*a*b"), true);
    EXPECT_EQ(solution.isMatch("mississippi", "mis*is*p*."), false);
    EXPECT_EQ(solution.isMatch("abcd", "a.*"), true);
    EXPECT_EQ(solution.isMatch("abcd", "ac.*"), false);
}

DEFINE_string(cmd, "", "cmd");
DEFINE_string(logdir, "./log", "logdir");


int32_t main(int32_t argc, char **argv)
{
    gflags::ParseCommandLineFlags(&argc, &argv, false);
    testing::InitGoogleTest(&argc, argv);
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = FLAGS_logdir;

    //LOG(INFO) << FLAGS_cmd;

    int32_t ret = RUN_ALL_TESTS();
    LOG(INFO) << "ret:" << ret;

    google::ShutdownGoogleLogging();
    return 0;
}


//class Solution
//{
//public:
//    bool isMatch(string s, string p)
//    {
//        if (!checkS(s) || !checkP(p)) return false;
//        char *s_start = &s.at(0), *s_c = s_start;
//        char *p_start = &p.at(0), *p_c = p_start, *p_next = p_c + 1;
//
//        //不止不休
//		while (*s_c != '\0' && *p_c != '\0') {
//			//cout << "s_c " << *s_c << ", p_c " << *p_c << endl;
//
//			//未匹配
//			if (*s_c != *p_c && *p_c != '.') {
//				if (*p_next == '*') {
//					p_c = p_next + 1;
//					p_next = p_c + 1;
//					if (*p_c == '\0') {
//		        		cout << "*p_c == '\0'" << endl;
//						return false;
//					}
//					continue;
//				} else if ((p_c - p_start > 1
//								&& *(p_c - 1) == '*'
//								&& (*(p_c - 2) == *p_c || *(p_c - 2) == '.'))) {
//					p_c = p_c + 1;
//					p_next = p_c + 1;
//					continue;
//				} else {
//					return false;
//				}
//			}
//			//匹配
//			else {
//				++s_c;
//				if (*p_next == '*') {
//					continue;
//				} else {
//					++p_c;
//					++p_next;
//				}
//			}
//        }
//
//		cout << "s_c " << *s_c << ", p_c " << *p_c << ", p_next" << *p_next << endl;
//
//        if (*s_c != '\0') {
//        	cout << "*s_c != '\0'" << endl;
//        	return false;
//        } else if (*p_c != '\0') {
//        	if (*p_next == '*' && *(p_next + 1) == '\0') {
//        		return true;
//        	} else if (*p_next == '*'
//        			&& *p_c == *(p_next + 1)
//					&& *(p_next + 2) == '\0') {
//        		return true;
//        	} else {
//        		cout << "else" << endl;
//        		return false;
//        	}
//        }
//        return true;
//    }
//
//    bool checkS(string &s)
//    {
//        if (s.empty()) return false;
//        for (int i = 0, len = s.length(); i < len; ++i)
//        {
//            char c = s.at(i);
//            if (c < 'a' || c > 'z')
//            {
//                cout << c << endl;
//                return false;
//            }
//        }
//        return true;
//    }
//
//    bool checkP(string &s)
//    {
//        if (s.empty()) return false;
//        for (int i = 0, len = s.length(); i < len; ++i)
//        {
//            char c = s.at(i);
//            if ((c < 'a' || c > 'z') && c != '*' && c != '.')
//            {
//                cout << c << endl;
//                return false;
//            }
//        }
//        return true;
//    }
//};
