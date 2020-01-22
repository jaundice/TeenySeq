// MidiEvent.h

#ifndef _MIDIEVENT_h
#define _MIDIEVENT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
namespace ByteFarm
{
	namespace TeenySeq
	{
		namespace Events
		{
			enum class MidiEventType : byte
			{
				Note = 1,
				CC = 2,
				NRPN = 3,
				SysEx = 4
			};

			struct MidiEvent
			{
			public:
				uint32_t Epoch;

				MidiEvent(uint32_t epoch)
				{
					Epoch = epoch;
				}

				virtual MidiEventType EventType() = 0;

				virtual ~MidiEvent()
				{
				}
			};

			struct NoteEvent : public MidiEvent
			{
			public:
				uint32_t GateLength;
				byte Note;
				byte OnVelocity;
				byte OffVelocity;

				NoteEvent(uint32_t epoch, uint32_t length, byte onVelocity, byte offVelocity) : MidiEvent(epoch)
				{
					GateLength = length;
					OnVelocity = onVelocity;
					OffVelocity = offVelocity;
				}

				MidiEventType EventType() override
				{
					return MidiEventType::Note;
				}

				~NoteEvent() override
				{
				};
			};

			struct CCParameterEvent : public MidiEvent
			{
			public:
				byte CC;
				byte Value;

				MidiEventType EventType() override
				{
					return MidiEventType::CC;
				}
			};
		}
	}
}
#endif
