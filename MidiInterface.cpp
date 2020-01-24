// 
// 
// 

#include "MidiInterface.h"
using namespace ByteFarm;
using namespace TeenySeq;


Midi::MidiInterface::~MidiInterface()
{
}

Midi::UsbMidiPort::~UsbMidiPort()
{
}

Midi::DinMidiPort::DinMidiPort(HardwareSerial& serial, String name)
{
	iface = new midi::MidiInterface<HardwareSerial>(serial);
	Name = name;
}

Midi::DinMidiPort::~DinMidiPort()
{
	delete iface;
}
