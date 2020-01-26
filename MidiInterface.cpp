// 
// 
// 

#include "MidiInterface.h"
using namespace ByteFarm;
using namespace TeenySeq;


Midi::MidiInterface::~MidiInterface()
{
}

UsbMidiPort::~UsbMidiPort()
{
}

DinMidiPort::DinMidiPort(HardwareSerial& serial, String name)
{
	iface = new midi::MidiInterface<HardwareSerial>(serial);
	Name = name;
}

DinMidiPort::~DinMidiPort()
{
	delete iface;
}
