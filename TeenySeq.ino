/*
	Name:       TeenySeq.ino
	Created:	09/01/2020 19:48:19
	Author:     RALPH\John
*/

#include "IntervalClock.h"
#include "Clock.h"
#include "Enumerator.h"
#include "MidiInterface.h"
#include "MidiPattern.h"
#include "MidiEvent.h"
#include "TeenySequencer.h"

namespace MainApp
{
	using namespace ByteFarm::TeenySeq::Events;

	MidiEvent* getEvent()
	{
		return new NoteEvent(3, 12, 64, 64);
	}
}

ByteFarm::TeenySeq::TeenySequencer teenyseq = ByteFarm::TeenySeq::TeenySequencer();

void setup()
{
	Serial.begin(9600);
	Serial.println(F("here"));
	using namespace ByteFarm::TeenySeq;
	using namespace Midi;
	using namespace Events;
	using namespace MainApp;

	Serial.println(F("loading start"));
	long startTime = micros();
	int count = 6200;

	auto tracks = teenyseq.GetTrackEnumerator();
	auto pattern = tracks->GetCurrent()->CreatePattern();
	for (int16_t i = 0; i < count; i++)
	{
		if (i > 0 && i % (count / (teenyseq.GetNumTracks() - 1)) == 0)
		{
			Serial.println(F("Current idx: ") + String(i));
			Serial.println(F("Moving to next track"));
			tracks->Next();
			Serial.println(F("Creating new pattern"));
			pattern = tracks->GetCurrent()->CreatePattern();
			Serial.println(F("pattern created"));
		}

		NoteEvent* n = new NoteEvent(10 + (i * 100), 200, 64, 64);
		pattern->InsertEvent(n);
		n = new NoteEvent((count - i) * 100, 200, 64, 64);
		pattern->InsertEvent(n);
	}


	Serial.println(F("loading done in "));
	Serial.println((micros() - startTime));
}


void loop()
{
	//Serial.println("in loop");


	uint16_t i = 0;
	long startTime = micros();
	auto tracks = teenyseq.GetTrackEnumerator();

	do
	{
		auto track = tracks->GetCurrent();

		auto patterns = track->GetPatternEnumerator();

		do
		{
			auto notes = patterns->GetCurrent()->GetEnumerator();
			do
			{
				i++;
			}
			while (notes->Next());
			delete notes;
		}
		while (patterns->Next());
		delete patterns;
	}
	while (tracks->Next());

	delete tracks;
	Serial.println();
	Serial.print(i);
	Serial.print(F(" events read in "));
	Serial.print((micros() - startTime));


	//delay(1000);
}
