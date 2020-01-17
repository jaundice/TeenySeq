// SequencerTrack.h

#ifndef _SEQUENCERTRACK_h
#define _SEQUENCERTRACK_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "SortedLinkedList.h"
#include "MidiPattern.h"
#include "MidiInterface.h"
#include "MidiInstrument.h"
#include "StringComparer.h"

namespace ByteFarm {
	namespace TeenySeq {
		using namespace ByteFarm::TeenySeq;
		using namespace ByteFarm::DataStructures;
		using namespace ByteFarm::TeenySeq::Midi;

		class SequencerTrack {
			MidiPatternComparer mpcmpr = MidiPatternComparer();

			SortedLinkedList<MidiPattern> _patterns = SortedLinkedList<MidiPattern>(&mpcmpr);
			MidiInterface* _inputDevice;
			byte _inputChannel;
			MidiInstrument* _midiInstrument;

		public:
			String Name;

			SequencerTrack(String name) {
				Name = name;
			}

			Enumerator<MidiPattern>* GetPatternEnumerator() {
				return _patterns.GetEnumerator();
			}


			MidiPattern* CreatePattern() {
				MidiPattern* pattern = new MidiPattern();
				_patterns.Insert(pattern);
				return pattern;
			}
		};

		class SequencerTrackComparer : public SortComparer<SequencerTrack> {

		public:
			virtual int Compare(SequencerTrack* a, SequencerTrack* b) override {
				return stringComparer->Compare(&(a->Name), &(b->Name));
			}
		};
	}
}

#endif

