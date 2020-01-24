// 
// 
// 

#include "SequencerTrack.h"

ByteFarm::TeenySeq::SequencerTrack::SequencerTrack(String name)
{
	PatternAdded = new EventHandler<SequencerTrack, MidiPattern>();
	Name = name;
}

ByteFarm::Enumerator<ByteFarm::TeenySeq::MidiPattern>* ByteFarm::TeenySeq::SequencerTrack::GetPatternEnumerator() const
{
	return _patterns->GetEnumerator();
}

ByteFarm::TeenySeq::MidiPattern* ByteFarm::TeenySeq::SequencerTrack::CreatePattern()
{
	MidiPattern* pattern = new MidiPattern();
	_patterns->Insert(pattern);
	PatternAdded->Trigger(this, pattern);
	return pattern;
}

ByteFarm::TeenySeq::SequencerTrack::~SequencerTrack()
{
	_patterns->Clear();
	delete _patterns;

	PatternAdded->Clear();
	delete PatternAdded;
}
