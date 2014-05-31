#ifndef RAW_IO_HPP
#define RAW_IO_HPP

#include "base/time.h"

namespace raw_io
{
	struct Digital
	{
		base::Time time;
		bool data;
	};

	struct Analogic
	{
		base::Time time;
		float data;
	};

} // end namespace raw_io

#endif // _RAW_IO_HPP_
