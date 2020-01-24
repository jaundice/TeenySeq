// MidiDevice.h

#ifndef _MIDIDEVICE_h
#define _MIDIDEVICE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#define USB_MIDI

#include <MIDI.h>

namespace ByteFarm
{
	namespace TeenySeq
	{
		namespace Midi
		{
			using namespace midi;

			class MidiInterface
			{
			public:
				String Name;

				virtual ~MidiInterface();;
			};

			class UsbMidiPort : public MidiInterface
			{
			public:
				UsbMidiPort(byte portNumber)
				{
				};

				~UsbMidiPort() override;;
			};

			class DinMidiPort : public MidiInterface
			{
				midi::MidiInterface<HardwareSerial>* iface;
			public:
				DinMidiPort(HardwareSerial& serial, String name);;

				~DinMidiPort() override;;
			};
		}
	}
}

#endif
