// 
// 
// 

#include "UIManager.h"
using namespace ByteFarm;
using namespace TeenySeq;
using namespace UI;

UIManager::UIManager(MainButtonMatrix* mainMatrix, MasterControls* masterControls,
                     TrackControls* track1Controls, TrackControls* track2Controls,
                     TrackControls* track3Controls,
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

void UIManager::SetActiveLayout(UILayoutBase* layout)
{
	if (!(ActiveLayout == nullptr))
	{
		ActiveLayout->Unwire();
	}

	ActiveLayout = layout;
	ActiveLayout->Wireup();
}
