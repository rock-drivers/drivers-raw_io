rock_library(raw_io
    SOURCES
        PWMServo.cpp
    HEADERS
        Digital.hpp Analog.hpp PWMDutyDurations.hpp PWMServoConfiguration.hpp
        PWMServo.hpp
    DEPS_PKGCONFIG base-types)
