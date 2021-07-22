#include <iostream>
#include <vector>
using namespace std;

int32_t main(int32_t argc, char **argv)
{
    vector<int> v = {1,2,3,4,5,6,7};
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
    	if (*iter == 4) {
    		v.erase(iter);
    	}
    	cout << *iter << endl;
    }
    cout << "after" << endl;
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
    	cout << *iter << endl;
    }
    return 0;
}

