// IntervalClock.h

#ifndef _INTERVALCLOCK_h
#define _INTERVALCLOCK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
namespace ByteFarm
{
	namespace TeenySeq
	{

		class IntervalClock
		{
			IntervalTimer _timer = IntervalTimer();

		public:
			IntervalClock()
			{

			}
		};

	}
}
#endif

