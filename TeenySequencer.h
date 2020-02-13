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
#include "UIManager.h"
#include "Collection.h"
//#include <uClock.h>
#include "Clock.h"
#include <functional>

namespace ByteFarm
{
	namespace TeenySeq
	{
		using namespace Midi;
		using namespace DataStructures;
		using namespace UI;
		//using namespace umodular::clock;
		
		class TeenySequencer
		{

			Clock _clock = Clock();

			std::function<void(SequencerTrack*, MidiPattern*)> _patternAddedCallback = std::bind(
				&TeenySequencer::PatternAdded, this, std::placeholders::_1, std::placeholders::_2);

			Collection<MidiInterface>* _devices = new LinkedList<MidiInterface>();
			Collection<SequencerTrack>* _tracks = new LinkedList<SequencerTrack>();

			MainButtonMatrix _mainMatrix = MainButtonMatrix();
			MasterControls _masterControls = MasterControls();
			TrackControls _trackControls[3]{
				TrackControls(&Wire, 1), TrackControls(&Wire, 2), TrackControls(&Wire, 3)
			};

			UIManager _UIManager = UIManager(&_mainMatrix, &_masterControls, &_trackControls[1], &_trackControls[2],
			                                 &_trackControls[3], _tracks);


		public:
			TeenySequencer();;

			int GetNumTracks();

			Enumerator<SequencerTrack>* GetTrackEnumerator() const;

			Enumerator<MidiInterface>* GetMidiDeviceEnumerator() const;

			void PatternAdded(SequencerTrack* track, MidiPattern* pattern);

			virtual  ~TeenySequencer();
		};
	}
}


#endif
