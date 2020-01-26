// CallbackWrapper.h

#ifndef _CALLBACKWRAPPER_h
#define _CALLBACKWRAPPER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <functional>
namespace ByteFarm
{
	namespace Events
	{
		template <class U, class V>
		class CallbackWrapper
		{
		public:
			//typedef void (*Callback)(U*, V*);
			CallbackWrapper(std::function<void(U*, V*)> *  cb);

			void Call(U* sender, V* arg);
		private:
			std::function<void(U*,V*)> * _cb;
		};

		template <class U, class V>
		CallbackWrapper<U, V>::CallbackWrapper(std::function<void(U*, V*)> * cb)
		{
			_cb = cb;
		}

		template <class U, class V>
		void CallbackWrapper<U, V>::Call(U* sender, V* arg)
		{
			(_cb)(sender, arg);
		}
	}
}

#endif
