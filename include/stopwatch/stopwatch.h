#pragma once

// #include <chrono>

namespace eld
{
    template <typename ClockType,
            typename DurationCaster>
    class stopwatch
    {
    public:

        using clock_type = ClockType;
        using duration = typename clock_type::duration;

        stopwatch()
             : start_(clock_type::now())
        {}

        void reset()
        {
            start_ = clock_type::now();
        }

        typename clock_type::duration result() const
        {
            return clock_type::now() - start_;
        }

        template<typename Duration>
        Duration result() const
        {
            // return std::chrono::duration_cast<Duration>(result()); // TODO: remove this
            return DurationCaster()(Duration(), result());
        }

        template<typename Duration>
        operator Duration() const
        {
            return result<Duration>();
        }

        // This is ugly and does not work
//        template <typename Caster>
//        auto operator()(Caster caster) -> decltype(Caster::operator()(typename clock_type::time_point))
//        {
//            return caster(result());
//        }

    private:
        typename clock_type::time_point start_;
    };

}


