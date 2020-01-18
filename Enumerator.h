// Enumerator.h

#ifndef _ENUMERATOR_h
#define _ENUMERATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
namespace ByteFarm {
	namespace DataStructures {

		template <class T>
		class Enumerator {
		public:
			virtual T* GetCurrent() = 0;
			virtual bool Next() = 0;

			virtual ~Enumerator() {};
		};

	}
}
#endif

