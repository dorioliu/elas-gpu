#include "timer.h"

void Timer::gettimeofday(struct timeval* tv)
{
    auto time_now = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
    auto duration_in_s = std::chrono::duration_cast<std::chrono::seconds>(time_now.time_since_epoch()).count();
    auto duration_in_us = std::chrono::duration_cast<std::chrono::microseconds>(time_now.time_since_epoch()).count();
    tv->tv_sec = duration_in_s;
    tv->tv_usec = duration_in_us;
}

void Timer::push_back_time()
{
    timeval curr_time;
    gettimeofday(&curr_time);
    time.push_back(curr_time);
}

void Timer::stop() {
    if (time.size() <= desc.size())
        push_back_time();
}

void Timer::plot() {
    stop();
    float total_time = 0;
    for (int32_t i = 0; i < desc.size(); i++) {
        float curr_time = getTimeDifferenceMilliseconds(time[i], time[i + 1]);
        total_time += curr_time;
        std::cout.width(30);
        std::cout << desc[i] << " ";
        std::cout << std::fixed << std::setprecision(1) << std::setw(6);
        std::cout << curr_time;
        std::cout << " ms" << std::endl;
    }
    std::cout << "========================================" << std::endl;
    std::cout << "                    Total time ";
    std::cout << std::fixed << std::setprecision(1) << std::setw(6);
    std::cout << total_time;
    std::cout << " ms" << std::endl << std::endl;
}

float Timer::getTimeDifferenceMilliseconds(timeval a, timeval b) {
    return ((float)(b.tv_sec - a.tv_sec)) * 1e+3 +
        ((float)(b.tv_usec - a.tv_usec)) * 1e-3;
}

void Timer::start(std::string title) {
    desc.push_back(title);
    push_back_time();
}


void Timer::reset() {
    desc.clear();
    time.clear();
}
