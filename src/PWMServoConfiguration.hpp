#ifndef RAW_IO_PWMSERVOCONFIGURATION_HPP
#define RAW_IO_PWMSERVOCONFIGURATION_HPP

#include <base/Angle.hpp>
#include <base/Time.hpp>

#include <cstdint>

namespace raw_io {
    /** PWMServoTask will convert the input joint command into a PWM command assuming
     * a proportional response, minus the deadband
     */
    struct PWMServoConfiguration {
        /** PWM that will place the servo in the angle_min position */
        std::uint32_t pwm_min = 0;
        /** Angle at pwm_min */
        base::Angle angle_min;

        /** PWM that will place the servo in the angle_max position */
        std::uint32_t pwm_max = 0;
        /** Angle at pwm_min */
        base::Angle angle_max;

        /** Angular difference to the center under which the PWM returned will be
         * \c pwm_center (that is, the center of the deadband)
         */
        base::Angle angle_center_threshold = base::Angle::fromDeg(1);

        /** PWM around which there is a deadband */
        std::uint32_t pwm_center = 0;

        /** Width of the deadband, that is width around the center PWM that
         * will not generate any response from the servo
         */
        std::uint32_t pwm_deadband_width = 0;
    };
}

#endif