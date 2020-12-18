#pragma once

#include <chrono>

#include "stopwatch/stopwatch_base.h"

namespace eld
{
    namespace detail
    {
        struct chrono_caster
        {
            template <typename To, typename From>
            constexpr To operator()(To, From fromDuration) const
            {
                return std::chrono::duration_cast<To>(fromDuration);
            }
        };
    }

    template <typename ClockType>
    using stopwatch_std = stopwatch_base<ClockType, detail::chrono_caster>;

    using steady_stopwatch = stopwatch_std<std::chrono::steady_clock>;
}
