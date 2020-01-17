// MidiInstrument.h

#ifndef _MIDIINSTRUMENT_h
#define _MIDIINSTRUMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "MidiInterface.h"
namespace ByteFarm {
	namespace TeenySeq {
		using namespace ByteFarm::TeenySeq::Midi;

		class MidiInstrument {
			String Name;
			MidiInterface* _outputInterface;
			byte outputChannel;
			byte _controllerMap[12];
		};

	}
}
#endif

