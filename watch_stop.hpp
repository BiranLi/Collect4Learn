#ifndef _WATCH_STOP_HPP_
#define _WATCH_STOP_HPP_

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif

#include <cstddef>

class CStopWatch
{
public:
    CStopWatch()
        : elapsed_(0) {
#ifdef _WIN32
        QueryPerformanceFrequency(&freq_);
#endif
    }
    ~CStopWatch(){}
public:
    void start() {
#ifdef _WIN32
        QueryPerformanceCounter(&begin_time_);
#else
        gettimeofday(&begin_time_, NULL);
#endif
    }
    void stop()
    {
#ifdef _WIN32
        LARGE_INTEGER end_time;
        QueryPerformanceCounter(&end_time);
        elapsed_ += (end_time.QuadPart - begin_time_.QuadPart) * 1000000 / freq_.QuadPart;
#else
        timeval end_time;
        gettimeofday(&end_time, NULL);
        elapsed_ += (end_time.tv_usec - begin_time_.tv_usec) + 1000000 * (end_time.tv_sec - begin_time_.tv_sec);
#endif
    }
    void restart()
    {
        elapsed_ = 0;
        start();
    }
    //us
    double elapsed()
    {
        return static_cast<double>(elapsed_);
    }
    //ms
    double elapsed_ms()
    {
        return elapsed_ / 1000.0;
    }
    //s
    double elapsed_second()
    {
        return elapsed_ / 1000000.0;
    }

private:

#ifdef _WIN32
    LARGE_INTEGER freq_;
    LARGE_INTEGER begin_time_;
#else
    timeval begin_time_;
#endif
    long long elapsed_;
};

#endif // _WATCH_STOP_HPP_