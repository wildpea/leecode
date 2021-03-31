#include "via_util.h"

class Solution
{
public:
	string minNumber(vector<int>& nums) {
		if (nums.size() == 0) return "";
    	string str;
    	vector<string> str_nums;
    	for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
    		str_nums.push_back(to_string(*iter));
    	}

    	sort(str_nums.begin(), str_nums.end(), [](const string& v1, const string &v2) {
			return (v1+v2) < (v2+v1);
		});

    	for (auto iter = str_nums.begin(); iter != str_nums.end(); ++iter) {
    		str += *iter;
    	}
    	return str;
    }

//    static int inner_compare(const string &v1, const string &v2) {
//    	//return (v2 + v1).compare(v1 + v2);
////
//
//    	//return (v1 + v2).compare(v2 + v1);
//    }
};

TEST(test_Solution, test_1)
{
    Solution solution;

//    输入: [10,2]
//    输出: "102"
//    示例 2:
//
//    输入: [3,30,34,5,9]
//    输出: "3033459"

    vector<int> v1 = {10,2,31};
    vector<int> v2 = {3,30,34,5,9};
//    VIA::ViaSTL::printC<int>(v2, "init");
//    sort(v2.begin(), v2.end(), [](int x1, int x2) {
//    	return x1 > x2;
//    });
//    VIA::ViaSTL::printC<int>(v2, "sort");
//
//    vector<string> s2 = {"3", "30", "34", "5", "9"};
//    VIA::ViaSTL::printC<string>(s2, "init");
//    sort(s2.begin(), s2.end(), [](string &a1, string &a2) {
//    	//return a1+a2 > a2+a1;
//    	return a2+a1 > a1+a2;
//    });
//    VIA::ViaSTL::printC<string>(s2, "sort");


    string rst1 = solution.minNumber(v2);
    cout << rst1 << endl;
//    string s1 = "102";
//    EXPECT_STREQ(rst1, s1);
    //EXPECT_STREQ(solution.minNumber(v2), "3033459);
}
