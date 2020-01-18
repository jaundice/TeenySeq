// ClipLaunchLayout.h

#ifndef _CLIPLAUNCHLAYOUT_h
#define _CLIPLAUNCHLAYOUT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "UILayout.h"
#include "Collection.h"
#include "SequencerTrack.h"
#include "TrackControls.h"
#include "MainButtonMatrix.h"

namespace ByteFarm {
	namespace TeenySeq {
		namespace UI {
			using namespace ByteFarm::TeenySeq;
			using namespace ByteFarm::DataStructures;

			class ClipLaunchLayout :public UILayout<Collection<SequencerTrack>> {

				MainButtonMatrix* _mainButtonMatrix;
				TrackControls* _track1Controls;
				TrackControls* _track2Conrols;
				TrackControls* _track3Controls;

				virtual void WireModel(Collection<SequencerTrack>* model) override {

				}

				virtual void UnwireModel(Collection<SequencerTrack>* model) override {

				}

			public:

				ClipLaunchLayout(MainButtonMatrix* buttons, TrackControls* track1Controls, TrackControls* track2Controls, TrackControls* track3Controls) {
					_mainButtonMatrix = buttons;
					_track1Controls = track1Controls;
					_track2Conrols = track2Controls;
					_track3Controls = track3Controls;
				}

				virtual void Wire() override {

				}

				virtual void Unwire() override {

				}
			};

		}
	}
}


#endif

