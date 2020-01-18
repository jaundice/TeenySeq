// SingleTrackLayout.h

#ifndef _SINGLETRACKLAYOUT_h
#define _SINGLETRACKLAYOUT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SequencerTrack.h"
#include "UILayout.h"
#include "MainButtonMatrix.h"
#include "TrackControls.h"

namespace ByteFarm {
	namespace TeenySeq {
		namespace UI {
			class SingleTrackLayout :public UILayout<SequencerTrack> {
				uint8_t _matrixRowOffset = 0;
				uint8_t _matrixAvailableRows = 12;
				MainButtonMatrix* _matrix;
				TrackControls* _trackControls;

				virtual void UnwireModel(SequencerTrack* model) override {

				};

				virtual void WireModel(SequencerTrack* model) override {

				};


			public:
				SingleTrackLayout(MainButtonMatrix* matrix, TrackControls* trackControls, uint8_t matrixRowOffset, uint8_t avaliableMatrixRows) {
					_trackControls = trackControls;
					_matrix = matrix;
					_matrixAvailableRows = avaliableMatrixRows;
					_matrixRowOffset = matrixRowOffset;
				};

				void Wire() override {

				}

				void Unwire() override {

				}
			};

			class TripleTrackLayout :public UILayoutBase {
				MainButtonMatrix* _matrix;
				SingleTrackLayout* _track1;
				SingleTrackLayout* _track2;
				SingleTrackLayout* _track3;
				TrackControls* _track1Controls;
				TrackControls* _track2Controls;
				TrackControls* _track3Controls;

			public:
				TripleTrackLayout(MainButtonMatrix* matrix, TrackControls* track1Controls, TrackControls* track2Controls, TrackControls* track3Controls) {
					_track1Controls = track1Controls;
					_track2Controls = track2Controls;
					_track3Controls = track3Controls;
					_track1 = new SingleTrackLayout(matrix, track1Controls, 0, 4);
					_track2 = new SingleTrackLayout(matrix, track2Controls, 4, 4);
					_track3 = new SingleTrackLayout(matrix, track3Controls, 8, 4);
				}

				void SetModel(uint8_t slot, SequencerTrack* track) {
					switch (slot) {
					case 1:
						_track1->SetModel(track);
						break;
					case 2:
						_track2->SetModel(track);
						break;
					case 3:
					default:
						_track3->SetModel(track);
					}
				}

				void Wire() override {

				}

				void Unwire()override {

				}
			};

			class WholeMatrixSingleTrackLayout : public UILayout<SequencerTrack> {
				MainButtonMatrix* _matrix;
				TrackControls* _track1Controls;
				TrackControls* _track2Controls;
				TrackControls* _track3Controls;

				void WireModel(SequencerTrack* model) override {

				}
				void UnwireModel(SequencerTrack* model) override {

				}

			public:
				WholeMatrixSingleTrackLayout(MainButtonMatrix* matrix, TrackControls* track1Controls, TrackControls* track2Controls, TrackControls* track3Controls) {
					_track1Controls = track1Controls;
					_track2Controls = track2Controls;
					_track3Controls = track3Controls;
				};

				void Wire() override {

				};

				void Unwire() override {

				}
			};
		}
	}
}

#endif

