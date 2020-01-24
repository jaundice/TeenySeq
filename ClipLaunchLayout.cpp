// 
// 
// 

#include "ClipLaunchLayout.h"
#include "Collection.h"
#include "SequencerTrack.h"
using namespace ByteFarm;
using namespace DataStructures;
using namespace TeenySeq;
using namespace UI;

void ClipLaunchLayout::WireModel(Collection<SequencerTrack>* model)
{
}

void ClipLaunchLayout::UnwireModel(Collection<SequencerTrack>* model)
{
}

ClipLaunchLayout::ClipLaunchLayout(MainButtonMatrix* buttons, TrackControls* track1Controls,
                                   TrackControls* track2Controls, TrackControls* track3Controls)
{
	_mainButtonMatrix = buttons;
	_track1Controls = track1Controls;
	_track2Controls = track2Controls;
	_track3Controls = track3Controls;
}

void ClipLaunchLayout::Wireup()
{
}

void ClipLaunchLayout::Unwire()
{
}
