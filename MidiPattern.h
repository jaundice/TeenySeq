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

namespace ByteFarm {
	using namespace DataStructures;
	namespace TeenySeq {
		using namespace Events;
		using namespace ByteFarm::TeenySeq;

		class MidiEventComparer : public SortComparer<MidiEvent> {
		public:
			virtual int Compare(MidiEvent* a, MidiEvent* b) override {
				return
					a->Epoch < b->Epoch ? -1 :
					a->Epoch > b->Epoch ? 1 :
					a->EventType() == b->EventType() ? 0 :
					a->EventType() == MidiEventType::Note ? -1 : 1;
			};
		};



		class MidiPattern {
			SortedLinkedList<MidiEvent>* EventStorage;

		public:
			String Name;
			MidiPattern() {
				MidiEventComparer* cmpr = new MidiEventComparer();
				EventStorage = new SortedLinkedList<MidiEvent>(cmpr);
			};

			void InsertEvent(MidiEvent* evt) {
				EventStorage->Insert(evt);
			};

			void RemoveEvent(MidiEvent* evt) {
				EventStorage->Remove(evt);
			};

			void ClearEvents() {
				EventStorage->Clear();
			}

			Enumerator<MidiEvent>* GetEnumerator() {
				return EventStorage->GetEnumerator();
			}

		};

		class MidiPatternComparer : public SortComparer<MidiPattern> {

		public:
			virtual int Compare(MidiPattern* a, MidiPattern* b) override {
				return stringComparer->Compare(&(a->Name), &(b->Name));
			};
		};
	};

}


#endif

