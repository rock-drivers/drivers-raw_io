#ifndef RAW_IO_PWMDUTYDURATIONS_HPP
#define RAW_IO_PWMDUTYDURATIONS_HPP

#include <cstdint>
#include <base/Time.hpp>

namespace raw_io {
    /** Representation of a PWM command */
    struct PWMDutyDurations {
        /** @meta role logical_time */
        base::Time time;

        /** Duration of the ON part of the cycle, in nanoseconds */
        std::vector<std::uint32_t> on_durations;
    };
}

#endif
