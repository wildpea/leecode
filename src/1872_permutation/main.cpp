#include "via_util.h"

class Solution
{
public:

//	vector<string> permutation(string s) {
//			vector<string> rst;
//
//			int len = s.size();
//			map<int, int> cs;
//
//			int depth = 1;
//			set<string> ss;
//			curse(s, cs, len, depth, ss);
//
//			for (auto iter = ss.begin(); iter != ss.end(); ++iter) {
//				rst.push_back(*iter);
//			}
//
//			return rst;
//		}
//
//		void curse(string s, map<int, int> cs, int len, int depth, set<string> &rst) {
//			for (int i = 0; i < len; ++i) {
//				if (cs.find(i) == cs.end()) {
//					auto iter1 = cs.insert(make_pair(i, depth));
//					if (cs.size() == len) {
//						stringstream ss;
//						for (auto iter = cs.begin(); iter != cs.end(); ++iter) {
//							ss << s.at(iter->second - 1);
//						}
//						rst.insert(ss.str());
//					} else {
//						curse(s, cs, len, depth+1, rst);
//					}
//					cs.erase(iter1.first);
//				}
//			}
//		}

	vector<string> permutation(string s) {
		vector<string> rst;

		int len = s.size();
		int cs[len];
		for (int i = 0; i < len; ++i) {
			cs[i] = 0;
		}

		int depth = 1;
		set<string> ss;
		char *p = new char[len+1];
		*(p+len+1) = '\0';
		curse(s, cs, len, depth, p, ss);

		for (auto iter = ss.begin(); iter != ss.end(); ++iter) {
			rst.push_back(*iter);
		}

		delete[] p;
		return rst;
	}

	void curse(string s, int cs[], int len, int depth, char *p, set<string> &rst) {
		for (int i = 0; i < len; ++i) {
			if (cs[i] == 0) {
				cs[i] = depth;
				*(p+depth-1) = s.at(i);
				if (depth == len) {
					string r=p;
					rst.insert(r);
				} else {
					curse(s, cs, len, depth+1, p, rst);
				}
				cs[i] = 0;
			}
		}
	}

};

TEST(test_Solution, test_1)
{
    Solution solution;

    vector<string> ss = solution.permutation("abcdefgh");
//    vector<string> ss = solution.permutation("aab");
    printS(ss);
    //EXPECT_EQ(solution.run("abc"), 3);
}
