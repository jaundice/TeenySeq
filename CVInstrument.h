// CVInstrument.h

#ifndef _CVINSTRUMENT_h
#define _CVINSTRUMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Instrument.h"

namespace ByteFarm
{
	namespace TeenySeq
	{
		namespace Instruments
		{
			class CVInstrument : public Instrument
			{
			public :

				virtual ~CVInstrument()
				{
				}
			};
		}
	}
}

#endif
