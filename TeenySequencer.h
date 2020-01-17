// TeenySequencer.h

#ifndef _TEENYSEQUENCER_h
#define _TEENYSEQUENCER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include <Wire.h>
#include "MidiInterface.h"
#include "SortedLinkedList.h"
#include <string>
#include "MidiInterfaceComparer.h"
#include "SequencerTrack.h"
#include "MainButtonMatrix.h"
#include "MasterControls.h"
#include "TrackControls.h"


namespace ByteFarm {
	namespace TeenySeq {
		using namespace ByteFarm::TeenySeq::Midi;
		using namespace ByteFarm::DataStructures;
		using namespace ByteFarm::TeenySeq::UI;

		class TeenySequencer {
			SequencerTrackComparer scmpr = SequencerTrackComparer();
			MidiInterfaceComparer dcmpr = MidiInterfaceComparer();

			SortedLinkedList<MidiInterface> _devices = SortedLinkedList<MidiInterface>(&dcmpr);
			SortedLinkedList<SequencerTrack> _tracks = SortedLinkedList<SequencerTrack>(&scmpr);

			MainButtonMatrix  _mainMatrix = MainButtonMatrix();
			MasterControls _masterControls = MasterControls();
			TrackControls  _trackControls[3]{
				TrackControls(&Wire ,1),TrackControls(&Wire, 2),TrackControls(&Wire ,3)
			};

		public:
			TeenySequencer() {

				HardwareSerial serials[3]{ Serial1, Serial2, Serial3 };

				for (byte i = 0; i < 3; i++) {
					_devices.Insert(new DinMidiPort(serials[i], "DIN " + String(i)));
				}

				for (byte j = 0; j < 16; j++) {
					_devices.Insert(new UsbMidiPort(j));
				}
				;

				for (byte k = 0; k < 16; k++) {
					_tracks.Insert(new SequencerTrack("Track " + String(k)));
				}
			};

			int GetNumTracks() {
				return _tracks.GetCount();
			}

			Enumerator<SequencerTrack>* GetTrackEnumerator() {
				return _tracks.GetEnumerator();
			}

			Enumerator<MidiInterface>* GetMidiDeviceEnumerator() {
				return _devices.GetEnumerator();
			}

		};

	}
}


#endif
