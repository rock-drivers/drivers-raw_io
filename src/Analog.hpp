#ifndef RAW_IO_ANALOG_HPP
#define RAW_IO_ANALOG_HPP

#include <base/Time.hpp>

namespace raw_io
{
    struct Analog
    {
        base::Time time;
        float data;

        Analog(){}

        Analog(base::Time const& time, float data):
            time(time),
            data(data)
        {}
    };

} // end namespace raw_io

#endif // _RAW_IO_HPP_

