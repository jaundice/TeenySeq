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

namespace ByteFarm
{
	namespace TeenySeq
	{
		namespace UI
		{
			using namespace TeenySeq;
			using namespace DataStructures;

			class ClipLaunchLayout : public UILayout<Collection<SequencerTrack>>
			{
				MainButtonMatrix* _mainButtonMatrix;
				TrackControls* _track1Controls;
				TrackControls* _track2Controls;
				TrackControls* _track3Controls;


			public:


				ClipLaunchLayout(MainButtonMatrix* buttons, TrackControls* track1Controls,
				                 TrackControls* track2Controls, TrackControls* track3Controls);

				void WireModel(Collection<SequencerTrack>* model) override;

				void UnwireModel(Collection<SequencerTrack>* model) override;

				void Wireup() override;

				void Unwire() override;
			};
		}
	}
}


#endif
