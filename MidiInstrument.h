// MidiInstrument.h

#ifndef _MIDIINSTRUMENT_h
#define _MIDIINSTRUMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "MidiInterface.h"
#include "Instrument.h"

namespace ByteFarm
{
	namespace TeenySeq
	{
		namespace Instruments
		{
			using namespace Midi;
			using namespace TeenySeq;

			class MidiInstrument : public Instrument
			{
				MidiInterface* _outputInterface;
				byte outputChannel;
				byte _controllerMap[12];
			};
		}
	}
}
#endif
