// Instrument.h

#ifndef _INSTRUMENT_h
#define _INSTRUMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
namespace ByteFarm
{
	namespace TeenySeq
	{
		namespace Instruments
		{
			class Instrument
			{
			public:
				String Name;

				virtual ~Instrument() = 0;
			};
		}
	}
}

#endif
