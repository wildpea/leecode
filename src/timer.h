#ifndef LEECODE_SRC_TIMER_H_
#define LEECODE_SRC_TIMER_H_


#include <iostream>
#include <sys/time.h>

using namespace std;

class Timer
{
public:
    explicit Timer(int64_t max_process_time = 1 * 1000 * 1000) //unit by microsecond,default 1s
    {
        gettimeofday(&tv, NULL);
    }

    int32_t GetCost() {
        timeval _tve;
        gettimeofday(&_tve, NULL);
        return (_tve.tv_sec - tv.tv_sec) * 1000 + (_tve.tv_usec - tv.tv_usec) / 1000;
    }

    ~Timer()
    {
        int64_t start = tv.tv_sec * 1000000 + tv.tv_usec;
        gettimeofday(&tv, NULL);
        int64_t end = tv.tv_sec * 1000000 + tv.tv_usec;
        int64_t cost = end - start;

        cout << "cost: " << cost << endl;
    }

private:
    struct timeval tv;

};


#endif /* LEECODE_SRC_TIMER_H_ */
