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
			= default;

			void setInterval(uint16_t interval)
			{
				_timer.update(interval);
			}

			void Stop()
			{
				_timer.end();
			}

			void Start(void(*funct)(), uint16_t interval)
			{
				_timer.begin(funct, interval);
			}
		};

	}
}
#endif

