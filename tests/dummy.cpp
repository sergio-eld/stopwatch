
#include <stopwatch/stopwatch_base.h>
#include <stopwatch/stopwatch_std.h>

#include <iostream>
#include <chrono>
#include <thread>

// this is inconvenient
struct DurationCaster
{
    template<typename ToDuration, typename FromDuration>
    constexpr ToDuration operator()(ToDuration, FromDuration fromDuration) const
    {
        return std::chrono::duration_cast<ToDuration>(fromDuration);
    }
};

int main()
{

    eld::stopwatch_base<std::chrono::steady_clock, DurationCaster> steadyWatch{};

    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    std::chrono::nanoseconds nanoseconds = steadyWatch.result();
    std::cout << nanoseconds.count() << std::endl;

    std::chrono::milliseconds milliseconds = steadyWatch;
    std::cout << milliseconds.count() << std::endl;

    eld::steady_stopwatch steadyStopwatch{};

    std::chrono::milliseconds msec_steady = steadyStopwatch;
    std::cout << msec_steady.count() << std::endl;

    return 0;
}

