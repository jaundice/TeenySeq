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
#include "Collection.h"
#include "Events.h"
#include "Enumerator.h"
#include "Instrument.h"

namespace ByteFarm
{
	namespace TeenySeq
	{
		using namespace TeenySeq;
		using namespace DataStructures;
		using namespace Midi;
		using namespace ByteFarm::Events;
		using namespace Instruments;

		class SequencerTrack
		{
			//MidiPatternComparer mpcmpr = MidiPatternComparer();

			Collection<MidiPattern>* _patterns = new LinkedList<MidiPattern>();
			MidiInterface* _inputDevice;
			byte _inputChannel;
			Instrument* _instrument;

		public:
			String Name;
			//EventHandler<SequencerTrack, MidiPattern>*  PatternAdded = new EventHandler<SequencerTrack, MidiPattern>() ;


			SequencerTrack(String name)
			{
				Name = name;
			}

			Enumerator<MidiPattern>* GetPatternEnumerator()
			{
				return _patterns->GetEnumerator();
			}


			MidiPattern* CreatePattern()
			{
				MidiPattern* pattern = new MidiPattern();
				_patterns->Insert(pattern);
				//PatternAdded->Trigger(this, pattern);
				return pattern;
			}

			virtual ~SequencerTrack()
			{
				delete _patterns;
			}
		};

		//class SequencerTrackComparer : public SortComparer<SequencerTrack> {

		//public:
		//	virtual int Compare(SequencerTrack* a, SequencerTrack* b) override {
		//		return stringComparer->Compare(&(a->Name), &(b->Name));
		//	}
		//};
	}
}

#endif
