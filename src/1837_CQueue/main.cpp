#include "via_util.h"


/**
 * 输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]


 */

class CStack {
private:
	deque<int> d1;
	deque<int> d2;
	deque<int> *cur_insert;
	deque<int> *cur_pop;

public:
	CStack() {
    	cur_insert = &d1;
    	cur_pop = &d2;
    }

    void appendTail(int value) {
    	cur_insert->push_back(value);
    }

    int deleteHead() {
    	if (cur_insert->size() == 0) {
    		return -1;
    	}

    	while (cur_insert->size() > 1) {
    		cur_pop->push_back(cur_insert->front());
    		cur_insert->pop_front();
    	}

    	int x = cur_insert->front();
    	cur_insert->pop_front();

    	swap(cur_insert, cur_pop);

    	return x;
    }
};


class CQueue {
private:
	stack<int> cur_insert;
	stack<int> cur_pop;

public:
    CQueue() {
    }

    void appendTail(int value) {
    	cur_insert.push(value);
    }

    int deleteHead() {
    	int x = -1;

    	if (cur_pop.size() != 0) {
			x = cur_pop.top();
			cur_pop.pop();
			return x;
		}

    	while (cur_insert.size() > 0) {
    		cur_pop.push(cur_insert.top());
    		cur_insert.pop();
    	}

    	if (cur_pop.size() != 0) {
			x = cur_pop.top();
			cur_pop.pop();
			return x;
		}

    	return x;
    }
};


TEST(test_Solution, test_1)
{
	//["CQueue",]
	//[[],[],[12],[],[10],[9],[],[],[],[20],[],[1],[8],[20],[1],[11],[2],[],[],[],[]]
    CQueue* obj = new CQueue();
    cout << obj->deleteHead() << endl;	//"deleteHead","","","","","","","","","","","","","","","","","deleteHead","deleteHead","deleteHead"
    obj->appendTail(12);		//appendTail
    cout << obj->deleteHead() << endl;	//deleteHead
    obj->appendTail(10);	//appendTail
    obj->appendTail(9);		//appendTail
    cout << obj->deleteHead() << endl;	//deleteHead
    cout << obj->deleteHead() << endl;	//deleteHead
    cout << obj->deleteHead() << endl;	//deleteHead
    obj->appendTail(20);	//appendTail
    cout << obj->deleteHead() << endl;	//deleteHead
    obj->appendTail(1);	//appendTail
    obj->appendTail(8);	//appendTail
    obj->appendTail(20);//appendTail
    obj->appendTail(1);	//appendTail
    obj->appendTail(11);	//appendTail
    obj->appendTail(2);		//appendTail
    cout << obj->deleteHead() << endl;//deleteHead
    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;
//    cout << obj->deleteHead() << endl;
//    obj->appendTail(5);
//    obj->appendTail(2);
//    cout << obj->deleteHead() << endl;
//    cout << obj->deleteHead() << endl;
//
//
//
//    obj->appendTail(3);
//    cout << obj->deleteHead() << endl;
//    cout << obj->deleteHead() << endl;
//    EXPECT_EQ(solution.run("III"), 3);
}
