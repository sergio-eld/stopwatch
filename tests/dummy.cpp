
#include <stopwatch/stopwatch.h>

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

    eld::stopwatch<std::chrono::steady_clock, DurationCaster> steadyWatch{};

    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    std::chrono::nanoseconds nanoseconds = steadyWatch.result();
    std::cout << nanoseconds.count() << std::endl;

    std::chrono::milliseconds milliseconds = steadyWatch;
    std::cout << milliseconds.count() << std::endl;

    // This is ugly and does not work
//    milliseconds = steadyWatch([](typename decltype(steadyWatch)::duration from)
//            {
//        return std::chrono::duration_cast<std::chrono::milliseconds>(from);
//            });

    return 0;
}

