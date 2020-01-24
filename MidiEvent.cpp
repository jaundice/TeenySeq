// 
// 
// 

#include "MidiEvent.h"
//using namespace ByteFarm::TeenySeq::Midi;
using namespace ByteFarm::TeenySeq::Events;

MidiEventType NoteEvent::EventType()
{
	return MidiEventType::Note;
}

NoteEvent::~NoteEvent()
{
}
