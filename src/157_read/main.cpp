#include <string>
#include <set>
#include <map>
#include <vector>
#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

std::string str = "abcdefgjsdfasd";
static int read4(char *b) {
	static int x = 0;
	static int total = str.size();
	int y = min(x + 4, total);

	int rst = y-x;
	memset(b, '\0', 4);
	memcpy(b, (void*)(&str[x]), rst);

	x = y;
	return rst;
}

class Solution
{
public:
	int read(char *buf, int n) {
		int x = n / 4;
		char *b = new char[4];
		int y = 4;
		int rst = 0;
		int incre = 0;
		while (rst < n && y == 4) {
			cout << x << endl;
			y = read4(b);
			cout << "num: " << y << "b: " << string(b) << endl;
			incre = min(y, n-rst);
			memcpy(buf+rst, b, incre);
			rst += incre;
			cout << string(buf) << " rst: " << rst << "< y; " << y << endl;
		}
		delete[] b;
		return rst;
	}
};

TEST(test_Solution, test_1)
{
    Solution solution;

    const int n = 9;
    char *buf = new char[n];
    int r = solution.read(buf, n);

    cout << string(buf) << ", " << r << endl;
    delete[] buf;
    //EXPECT_EQ(solution.run("III"), 3);
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

