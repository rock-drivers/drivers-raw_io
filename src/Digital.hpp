#ifndef RAW_IO_DIGITAL_HPP
#define RAW_IO_DIGITAL_HPP

#include <base/Time.hpp>

namespace raw_io
{
    struct Digital
    {
        base::Time time;
        float data;
    };

} // end namespace raw_io

#endif // _RAW_IO_HPP_
