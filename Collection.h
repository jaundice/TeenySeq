// Collection.h

#ifndef _COLLECTION_h
#define _COLLECTION_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "Enumerator.h"
namespace ByteFarm {
	namespace DataStructures {

		template <class T>
		class Collection {
		public:
			virtual uint32_t GetCount()=0;
			virtual void Clear() = 0;
			virtual void Insert(T* item)=0;
			virtual void Remove(T* item) = 0;
			virtual Enumerator<T>* GetEnumerator() = 0;
			virtual T* GetItemAtIndex(uint32_t index) = 0;
			virtual ~Collection() {};
		};
	}
}

#endif

