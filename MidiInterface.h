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
#include <string>
#include "SortedLinkedList.h"

namespace ByteFarm {
	namespace TeenySeq {
		namespace Midi {



			using namespace midi;
			class MidiInterface {
			public:
				String Name;

			};

			class UsbMidiPort : public MidiInterface {

			public:
				UsbMidiPort(byte portNumber) {
					
				};
			};

			class DinMidiPort : public MidiInterface {
				midi::MidiInterface<HardwareSerial>* iface;
			public:
				DinMidiPort(HardwareSerial& serial, String name) {
					iface = new midi::MidiInterface<HardwareSerial>(serial);
					Name = name;		
				};

				~DinMidiPort() {
					delete iface;
				}
			};


		}
	}
}

#endif

