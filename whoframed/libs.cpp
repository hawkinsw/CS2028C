#include <chrono>
#include <thread>

using namespace std::literals;

bool more_frames() {
    std::this_thread::sleep_for(2000ms);
    return true;
}