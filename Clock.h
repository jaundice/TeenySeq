// Clock.h

#ifndef _CLOCK_h
#define _CLOCK_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//#include <avr/io.h>
//#include <avr/interrupt.h>
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
			float _bpm;
			uint16_t _microsPer96th;
			volatile uint32_t _pulse = 0;
			bool _running;
			static bool volatile _pulseNext;

			static void clockCallback()
			{
				_pulseNext = true;
			}

		public:
			EventHandler<Clock, const uint32_t> PulseEvent;
			EventHandler<Clock, void> StartEvent;
			EventHandler<Clock, void> StopEvent;
			EventHandler<Clock, void> ResetEvent;

			Clock()
			{
				SetBPM(126);
			}

			void OnMCULoop()
			{
				if (_pulseNext)
				{
					_pulseNext = false;
					const uint32_t p = ++_pulse;
					PulseEvent.Trigger(this, &p);
					
				}
			}

			void SetBPM(float bpm)
			{
				_bpm = bpm;
				const uint32_t microsPerBeat = 1000000.0 / bpm;
				_microsPer96th = microsPerBeat / 96;
				_clock.setInterval(_microsPer96th);
			}

			void Start()
			{
				if (!_running)
				{
					_running = true;
					StartEvent.Trigger(this, nullptr);
					_clock.Start(clockCallback, _microsPer96th);
					const uint32_t z = 0;
					PulseEvent.Trigger(this, &z);
				}
			}

			void Stop()
			{
				if (_running)
				{
					_running = false;
					_clock.Stop();
					StopEvent.Trigger(this, nullptr);
				}
				else
				{
					_pulse = 0;
					ResetEvent.Trigger(this, nullptr);
				}
			}
		};
	}
}


#endif
