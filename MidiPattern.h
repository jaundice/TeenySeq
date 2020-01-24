// MidiPattern.h

#ifndef _MIDIPATTERN_h
#define _MIDIPATTERN_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "SortedLinkedList.h"
#include "MidiEvent.h"
#include "StringComparer.h"
#include "Collection.h"

namespace ByteFarm
{
	using namespace DataStructures;

	namespace TeenySeq
	{
		using namespace Events;
		using namespace TeenySeq;

		class MidiEventComparer : public SortComparer<MidiEvent>
		{
		public:
			int Compare(MidiEvent* a, MidiEvent* b) override;;
		};


		class MidiPattern
		{
			MidiEventComparer cmpr = MidiEventComparer();

			Collection<MidiEvent>* EventStorage = new SortedLinkedList<MidiEvent>(&cmpr);

		public:
			String Name;

			MidiPattern();;

			void InsertEvent(MidiEvent* evt) const;;

			void RemoveEvent(MidiEvent* evt) const;;

			void ClearEvents() const;

			Enumerator<MidiEvent>* GetEnumerator() const;

			virtual ~MidiPattern();
		};

		class MidiPatternComparer : public SortComparer<MidiPattern>
		{
		public:
			int Compare(MidiPattern* a, MidiPattern* b) override
			{
				return stringComparer->Compare(&(a->Name), &(b->Name));
			};
		};
	};
}


#endif
