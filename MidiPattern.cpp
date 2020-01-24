// 
// 
// 

#include "MidiPattern.h"

int ByteFarm::TeenySeq::MidiEventComparer::Compare(MidiEvent* a, MidiEvent* b)
{
	return
		a->Epoch < b->Epoch
			? -1
			: a->Epoch > b->Epoch
			? 1
			: a->EventType() == b->EventType()
			? 0
			: a->EventType() == MidiEventType::Note
			? -1
			: 1;
}

ByteFarm::TeenySeq::MidiPattern::MidiPattern()
{
}

void ByteFarm::TeenySeq::MidiPattern::InsertEvent(MidiEvent* evt) const
{
	EventStorage->Insert(evt);
}

void ByteFarm::TeenySeq::MidiPattern::RemoveEvent(MidiEvent* evt) const
{
	EventStorage->Remove(evt);
}

void ByteFarm::TeenySeq::MidiPattern::ClearEvents() const
{
	EventStorage->Clear();
}

ByteFarm::Enumerator<ByteFarm::TeenySeq::MidiEvent>* ByteFarm::TeenySeq::MidiPattern::GetEnumerator() const
{
	return EventStorage->GetEnumerator();
}

ByteFarm::TeenySeq::MidiPattern::~MidiPattern()
{
	delete EventStorage;
}
