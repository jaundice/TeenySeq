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
		//auto cb = new CallbackWrapper<SequencerTrack, MidiPattern>(
		//	std::bind(TeenySequencer::PatternAdded, this, std::placeholders::_1, std::placeholders::_2)
		//);
		//t->PatternAdded->RegisterCallback(cb);
	}
}

int ByteFarm::TeenySeq::TeenySequencer::GetNumTracks()
{
	return _tracks->GetCount();
}

ByteFarm::Enumerator<ByteFarm::TeenySeq::SequencerTrack>* ByteFarm::TeenySeq::TeenySequencer::GetTrackEnumerator()
{
	return _tracks->GetEnumerator();
}

ByteFarm::Enumerator<ByteFarm::TeenySeq::MidiInterface>* ByteFarm::TeenySeq::TeenySequencer::GetMidiDeviceEnumerator()
{
	return _devices->GetEnumerator();
}

void ByteFarm::TeenySeq::TeenySequencer::PatternAdded(SequencerTrack* track, MidiPattern* pattern)
{
}
