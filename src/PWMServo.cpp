#include <raw_io/PWMServo.hpp>

using namespace raw_io;
using namespace std;

PWMServo::PWMServo(PWMServoConfiguration const& conf)
    : m_configuration(conf)
{
    m_pwm_deadband_start =
        m_configuration.pwm_center - m_configuration.pwm_deadband_width / 2;

    m_pwm_per_rad = (m_configuration.pwm_max - m_configuration.pwm_min -
                        m_configuration.pwm_deadband_width) /
                    (m_configuration.angle_max - m_configuration.angle_min).getRad();

    m_angle_center =
        base::Angle::fromRad(
            (m_pwm_deadband_start - m_configuration.pwm_min) / m_pwm_per_rad) +
        m_configuration.angle_min;
}

uint32_t PWMServo::toPWM(base::Angle const& angle) const
{
    if (angle < m_configuration.angle_min) {
        throw std::invalid_argument("angle below min angle");
    }
    else if (angle > m_configuration.angle_max) {
        throw std::invalid_argument("angle above max angle");
    }

    if (abs((angle - m_angle_center).getRad()) <
        m_configuration.angle_center_threshold.getRad()) {
        return m_configuration.pwm_center;
    }

    auto pwm = (angle - m_configuration.angle_min).getRad() * m_pwm_per_rad +
               m_configuration.pwm_min;
    if (pwm > m_pwm_deadband_start) {
        pwm += m_configuration.pwm_deadband_width;
    }
    return std::round(pwm);
}

base::Angle PWMServo::clampAngleToValidRange(base::Angle const& angle) const {
    if (angle < m_configuration.angle_min) {
        return m_configuration.angle_min;
    }
    else if (angle > m_configuration.angle_max) {
        return m_configuration.angle_max;
    }
    return angle;
}