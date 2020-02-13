// Clock.h

#ifndef _CLOCK_h
#define _CLOCK_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Events.h"
#include "IntervalClock.h"

namespace ByteFarm
{
	namespace TeenySeq
	{
		using namespace Events;
		class Clock
		{
		private:
			IntervalClock _clock;
		public:
			EventHandler<Clock, uint32_t> PulseEvent;
			EventHandler<Clock, void> StartEvent;
			EventHandler<Clock, void> StopEvent;
			EventHandler<Clock, void> ResetEvent;
			Clock()
			{

			}
		};
		
	}
}


#endif

