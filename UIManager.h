// UIManager.h

#ifndef _UIMANAGER_h
#define _UIMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "UILayout.h"
#include "SingleTrackLayout.h"
#include "MainButtonMatrix.h"
#include "MasterControls.h"
#include "TrackControls.h"
#include "ClipLaunchLayout.h"

namespace ByteFarm
{
	namespace TeenySeq
	{
		namespace UI
		{
			using namespace TeenySeq;

			class UIManager
			{
				UILayoutBase* ActiveLayout;
				WholeMatrixSingleTrackLayout* _wholeTrackLayout;
				TripleTrackLayout* _tripleTrackLayout;
				ClipLaunchLayout* _clipLaunchLayout;

				MainButtonMatrix* _mainMatrix;
				MasterControls* _masterControls;

				TrackControls* _track1Controls;
				TrackControls* _track2Controls;
				TrackControls* _track3Conrols;
				Collection<SequencerTrack>* _tracks;
			public:

				UIManager(MainButtonMatrix* mainMatrix, MasterControls* masterControls, TrackControls* track1Controls,
				          TrackControls* track2Controls, TrackControls* track3Controls,
				          Collection<SequencerTrack>* tracksCollection);

				void SetActiveLayout(UILayoutBase* layout);

				//void SetSequencer(TeenySequencer* seq) {
				//	_seq = seq;
				//}
			};
		}
	}
}
#endif
