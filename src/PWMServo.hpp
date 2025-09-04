#ifndef RAW_IO_PWMSERVO_HPP
#define RAW_IO_PWMSERVO_HPP

#include <raw_io/PWMServoConfiguration.hpp>

namespace raw_io {
    /** Conversion between an angular position command to a PWM command
     */
    class PWMServo {
        PWMServoConfiguration m_configuration;

        uint32_t m_pwm_deadband_start;
        float m_pwm_per_rad;
        base::Angle m_angle_center;

    public:
        PWMServo(PWMServoConfiguration const& conf);

        uint32_t toPWM(base::Angle const& angle) const;

        base::Angle getCenterAngle() const;

        base::Angle clampAngleToValidRange(base::Angle const& angle) const;
    };
}

#endif