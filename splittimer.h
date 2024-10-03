#ifndef SPLITTIMER_H
#define SPLITTIMER_H
#include <iostream>
#include <chrono>

class SplitTimer {
private:
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point lap_time;

public:
    void start() {
        start_time = std::chrono::steady_clock::now();
        lap_time = start_time;
    }

    void lap() {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lap_time);
        std::cout << "Run time: " << elapsed.count() << " ms" << std::endl;
        lap_time = now;
    }

    int stop() {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time);
        //std::cout << "Run time: " << elapsed.count() << " ms" << std::endl;
        return elapsed.count();
    }
};

/* example code
int main() {
    SplitTimer timer;
    timer.start();

    // Simulate some activity (e.g., running a lap)
    // You can call timer.recordLap() whenever needed.

    // Example: Record three laps
    for (int lap = 1; lap <= 3; ++lap) {
        std::cout << "Lap " << lap << std::endl;
        timer.recordLap();
    }

    return 0;
}
*/

#endif