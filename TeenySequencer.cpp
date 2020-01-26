// 
// 
// 

#include "TeenySequencer.h"

ByteFarm::TeenySeq::TeenySequencer::TeenySequencer()
{
	HardwareSerial serials[3]{Serial1, Serial2, Serial3};

	for (byte i = 0; i < 3; i++)
	{
		_devices->Insert(new DinMidiPort(serials[i], "DIN " + String(i)));
	}

	for (byte j = 0; j < 16; j++)
	{
		_devices->Insert(new UsbMidiPort(j));
	}

	for (byte k = 0; k < 16; k++)
	{
		auto t = new SequencerTrack("Track " + String(k));
		_tracks->Insert(t);
		t->PatternAdded->RegisterCallback(
			static_cast<std::function<void(SequencerTrack*, MidiPattern*)>*>(&_patternAddedCallback));
	}
}

int ByteFarm::TeenySeq::TeenySequencer::GetNumTracks()
{
	return _tracks->GetCount();
}

ByteFarm::Enumerator<ByteFarm::TeenySeq::SequencerTrack>* ByteFarm::TeenySeq::TeenySequencer::GetTrackEnumerator() const
{
	return _tracks->GetEnumerator();
}

ByteFarm::Enumerator<ByteFarm::TeenySeq::MidiInterface>* ByteFarm::TeenySeq::TeenySequencer::
GetMidiDeviceEnumerator() const
{
	return _devices->GetEnumerator();
}

void ByteFarm::TeenySeq::TeenySequencer::PatternAdded(SequencerTrack* track, MidiPattern* pattern)
{
}
