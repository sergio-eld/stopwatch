#pragma once

namespace eld
{
    template <typename ClockType,
            typename DurationCaster>
    class stopwatch
    {
    public:

        using clock_type = ClockType;
        using duration = typename clock_type::duration;
        using time_point = typename clock_type::time_point;

        stopwatch()
             : start_(clock_type::now())
        {}

        void reset()
        {
            start_ = clock_type::now();
        }

        duration result() const
        {
            return clock_type::now() - start_;
        }

        template<typename Duration>
        Duration result() const
        {
            return DurationCaster()(Duration(), result());
        }

        template<typename Duration>
        operator Duration() const
        {
            return result<Duration>();
        }

    private:
        time_point start_;
    };

}


