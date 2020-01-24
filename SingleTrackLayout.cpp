// 
// 
// 

#include "SingleTrackLayout.h"
using namespace ByteFarm;
using namespace TeenySeq;
using namespace UI;

void SingleTrackLayout::UnwireModel(SequencerTrack* model)
{
}

void SingleTrackLayout::WireModel(SequencerTrack* model)
{
}

void SingleTrackLayout::Wireup()
{
}

void SingleTrackLayout::Unwire()
{
}

TripleTrackLayout::TripleTrackLayout(MainButtonMatrix* matrix, TrackControls* track1Controls,
                                     TrackControls* track2Controls, TrackControls* track3Controls)
{
	_track1Controls = track1Controls;
	_track2Controls = track2Controls;
	_track3Controls = track3Controls;
	_track1 = new SingleTrackLayout(matrix, track1Controls, 0, 4);
	_track2 = new SingleTrackLayout(matrix, track2Controls, 4, 4);
	_track3 = new SingleTrackLayout(matrix, track3Controls, 8, 4);
}

void TripleTrackLayout::Wireup()
{
}

void TripleTrackLayout::Unwire()
{
}

void WholeMatrixSingleTrackLayout::WireModel(SequencerTrack* model)
{
}

void WholeMatrixSingleTrackLayout::UnwireModel(SequencerTrack* model)
{
}

WholeMatrixSingleTrackLayout::WholeMatrixSingleTrackLayout(MainButtonMatrix* matrix,
                                                           TrackControls* track1Controls,
                                                           TrackControls* track2Controls,
                                                           TrackControls* track3Controls)
{
	_matrix = matrix;
	_track1Controls = track1Controls;
	_track2Controls = track2Controls;
	_track3Controls = track3Controls;
}

void WholeMatrixSingleTrackLayout::Wireup()
{
}

void WholeMatrixSingleTrackLayout::Unwire()
{
}
