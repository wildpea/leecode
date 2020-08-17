#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

//int Min(int number1,int number2,int number3)
//{
//    int min = (number1 < number2) ? number1 : number2;
//    min = (min < number3) ? min : number3;
//    return min;
//}
//
////返回第index个丑数
//int GetUglyNumber(int index)
//{
//    if(index <= 0)
//    {
//        return 0;
//    }
//
//    int *pUglyNumbers = new int[index];
//    pUglyNumbers[0] = 1;
//    int nextUglyIndex = 1;
//
//    int *pMultiply2 = pUglyNumbers;
//    int *pMultiply3 = pUglyNumbers;
//    int *pMultiply5 = pUglyNumbers;
//
//    while(nextUglyIndex < index)
//    {
//        int min = Min(*pMultiply2 * 2,*pMultiply3 * 3,*pMultiply5 * 5);
//        pUglyNumbers[nextUglyIndex] = min;
//
//        while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
//        {
//            ++pMultiply2;
//        }
//        while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
//        {
//            ++pMultiply3;
//        }
//        while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
//        {
//            ++pMultiply5;
//        }
//
//        ++nextUglyIndex;
//    }
//
//    int ugly = pUglyNumbers[nextUglyIndex-1];
//    delete[] pUglyNumbers;
//    return ugly;
//
//}


class Solution
{
public:
    int run(int n)
    {
    	vector<int> v;
    	if (n == 1) return 1;
    	v.push_back(1);

    	auto iter2 = 0;
    	auto iter3 = 0;
    	auto iter5 = 0;

    	int i = 1;
    	while (++i <= n) {
    		int m = min(min(v[iter2] * 2, v[iter3] * 3), v[iter5] * 5);
    		v.push_back(m);
    		if (v[iter2] * 2 <= m) iter2++;
    		if (v[iter3] * 3 <= m) iter3++;
    		if (v[iter5] * 5 <= m) iter5++;
    	}
		for (auto iter = v.begin(); iter != v.end(); ++iter) {
			cout << ": " << *iter << endl;
		}

    	return *(v.end() - 1);
    }
};

TEST(test_Solution, test_1)
{
    Solution solution;


    EXPECT_EQ(solution.run(10), 12);
    EXPECT_EQ(solution.run(20), 36);
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

