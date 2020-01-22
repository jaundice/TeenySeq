// StringComparer.h

#ifndef _STRINGCOMPARER_h
#define _STRINGCOMPARER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "SortedLinkedList.h"

namespace ByteFarm
{
	namespace TeenySeq
	{
		using namespace DataStructures;

		class StringComparer : public SortComparer<String>
		{
		public :
			int Compare(String* a, String* b) override
			{
				return (a) == (b) ? 0 : (a) > (b) ? 1 : -1;
			}
		};

		static StringComparer* stringComparer = new StringComparer();
	}
}

#endif
