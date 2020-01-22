// MidiDeviceComparer.h

#ifndef _MIDIDEVICECOMPARER_h
#define _MIDIDEVICECOMPARER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "SortedLinkedList.h"
#include "MidiInterface.h"
#include "StringComparer.h"

namespace ByteFarm
{
	namespace TeenySeq
	{
		namespace Midi
		{
			using namespace DataStructures;
			using namespace Midi;
			using namespace TeenySeq;

			class MidiInterfaceComparer : public SortComparer<MidiInterface>
			{
			public:
				int Compare(MidiInterface* a, MidiInterface* b) override
				{
					return stringComparer->Compare(&(a->Name), &(b->Name));
				};
			};
		}
	}
}
#endif
