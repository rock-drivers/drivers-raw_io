#ifndef RAW_IO_DIGITAL_HPP
#define RAW_IO_DIGITAL_HPP

#include <base/Time.hpp>

namespace raw_io
{
    struct Digital
    {
        base::Time time;
        bool data;

        Digital(){}
        
        Digital(base::Time const& time, bool data):
            time(time),
            data(data)
        {}
    };

} // end namespace raw_io

#endif // _RAW_IO_HPP_
