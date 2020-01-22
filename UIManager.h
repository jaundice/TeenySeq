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
				          Collection<SequencerTrack>* tracksCollection)
				{
					_tracks = tracksCollection;
					_mainMatrix = mainMatrix;
					_masterControls = masterControls;
					_track1Controls = track1Controls;
					_track2Controls = track2Controls;
					_track3Conrols = track3Controls;

					_wholeTrackLayout = new WholeMatrixSingleTrackLayout(
						mainMatrix, track1Controls, track2Controls, track3Controls);
					_tripleTrackLayout = new TripleTrackLayout(mainMatrix, track1Controls, track2Controls,
					                                           track3Controls);
					_clipLaunchLayout = new ClipLaunchLayout
						(mainMatrix, track1Controls, track2Controls, track3Controls);

					if (_tracks->GetCount() > 0)
					{
						auto trackEnu = _tracks->GetEnumerator();

						uint8_t i = 0;
						do
						{
							if (i == 0)
							{
								_wholeTrackLayout->SetModel(trackEnu->GetCurrent());
							}
							_tripleTrackLayout->SetModel(i, trackEnu->GetCurrent());

							i++;
						}
						while (i < 3 && i < _tracks->GetCount());
					}
					SetActiveLayout(_wholeTrackLayout);
				}

				void SetActiveLayout(UILayoutBase* layout)
				{
					if (!(ActiveLayout == nullptr))
					{
						ActiveLayout->Unwire();
					}

					ActiveLayout = layout;
					ActiveLayout->Wire();
				}

				//void SetSequencer(TeenySequencer* seq) {
				//	_seq = seq;
				//}
			};
		}
	}
}
#endif
