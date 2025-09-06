#include <gtest/gtest.h>
#include <raw_io/PWMServo.hpp>

using namespace base;
using namespace raw_io;
using namespace std;

struct PWMServoTest : public ::testing::Test {
    PWMServoConfiguration configuration;
    PWMServo servo{configuration};

    PWMServoTest()
    {
        configuration.angle_min = Angle::fromRad(-0.5);
        configuration.angle_max = Angle::fromRad(-0.1);

        configuration.pwm_min = 200;
        configuration.pwm_center = 325;
        configuration.pwm_deadband_width = 50;
        configuration.pwm_max = 650;

        // angles between -0.5 and -0.4 are below deadband
        // angles between -0.4 and -0.1 are above deadband
        // there is 100 PWM per 0.1 radians
        servo = PWMServo{configuration};
    }
};

TEST_F(PWMServoTest, it_throws_if_the_angle_is_below_minimum)
{
    ASSERT_THROW(servo.toPWM(Angle::fromRad(-0.6)), invalid_argument);
}

TEST_F(PWMServoTest, it_throws_if_the_angle_is_above_maximum)
{
    ASSERT_THROW(servo.toPWM(Angle::fromRad(-0.05)), invalid_argument);
}

TEST_F(PWMServoTest, it_converts_values_below_the_deadband)
{
    ASSERT_EQ(250, servo.toPWM(Angle::fromRad(-0.45)));
}

TEST_F(PWMServoTest, it_converts_values_just_before_the_deadband)
{
    // 1 degree "threshold-to-center"
    ASSERT_EQ(283, servo.toPWM(Angle::fromRad(-0.4) - Angle::fromDeg(1.00001)));
}

TEST_F(PWMServoTest, it_returns_the_center_if_the_angle_is_nearer_than_the_threshold_negative)
{
    ASSERT_EQ(325, servo.toPWM(Angle::fromRad(-0.4) - Angle::fromDeg(0.99999)));
}

TEST_F(PWMServoTest, it_returns_the_center_if_the_angle_is_nearer_than_the_threshold_positive)
{
    ASSERT_EQ(325, servo.toPWM(Angle::fromRad(-0.4) + Angle::fromDeg(0.99999)));
}

TEST_F(PWMServoTest, it_converts_values_just_after_the_deadband)
{
    // 1 degree "threshold-to-center"
    ASSERT_EQ(367, servo.toPWM(Angle::fromRad(-0.4) + Angle::fromDeg(1.00001)));
}

TEST_F(PWMServoTest, it_converts_values_above_the_deadband)
{
    ASSERT_EQ(450, servo.toPWM(Angle::fromRad(-0.3)));
}