
# Generic template StopWatch library

This is header-only template library that provides a convenience `stopwatch` class to measure 
time elapsed from `stopwatch` object creation or its being reset.
The `stopwatch` class is a template that reqiures two arguments: 
- clock type
- duration caster

Clock Type class must be std-compliant, it has to provide
- `clock_type::duration` [type][type_duration]
- `clock_type::time_point` [type] [type_time_point]

Example for a duration caster that uses `std::chrono::duration_cast`:
```C++
struct DurationCaster
{
    template<typename ToDuration, typename FromDuration>
    constexpr ToDuration operator()(ToDuration, FromDuration fromDuration) const
    {
        return std::chrono::duration_cast<ToDuration>(fromDuration);
    }
};
```

## Example usage:
```C++
#include <stopwatch/stopwatch.h>

using SteadyStopWatch = eld::stopwatch<std::chrono::steady_clock, DurationCaster>;

// initialize and start stopwatch from current time
SteadyStopWatch stopWatch{};

// do something

// get elapsed time automatically casted to milliseconds
std::chrono::milliseconds msecs = stopWatch;

// restart stopwatch from now
stopWatch.reset();
```

See tests/dummy.cpp

## Using with CMake
Library provides an installation script.
From command line run:
> mkdir build<br>
> cd build<br>
> cmake .. -DCMAKE_INSTALL_PREFIX=*path_to_installation_folder* -DCMAKE_BUILD_TYPE=Release

Then in your project's `CMakeLists.txt`
```CMake
find_package(eld::stopwatch)
target_link_libraries(YOUR_TARGET PUBLIC eld::stopwatch)
```

You can also use it via `add_subdirectory`, 
but then do not use an `eld::` namespace when linking with CMake.

[type_duration]: https://en.cppreference.com/w/cpp/chrono/duration
[type_time_point]: https://en.cppreference.com/w/cpp/chrono/time_point