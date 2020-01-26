// Events.h

#ifndef _EVENTS_h
#define _EVENTS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "SortedLinkedList.h"
#include "Enumerator.h"
#include <functional>

namespace ByteFarm
{
	namespace Events
	{
		using namespace DataStructures;

		template <class U, class V>
		class EventHandler
		{
		protected:
			LinkedList<std::function<void(U*, V*)>>* _handlers;

		public:
			EventHandler();;

			void RegisterCallback(std::function<void(U*, V*)>* cb);;

			void RemoveCallback(std::function<void(U*, V*)>* cb);;

			void Clear();;

			void Trigger(U* sender, V* args);;

			virtual ~EventHandler();;
		};

		template <class U, class V>
		EventHandler<U, V>::EventHandler()
		{
			_handlers = new LinkedList<std::function<void(U*, V*)>>();
		}

		template <class U, class V>
		void EventHandler<U, V>::RegisterCallback(std::function<void(U*, V*)>* cb)
		{
			_handlers->Insert(cb);
		}

		template <class U, class V>
		void EventHandler<U, V>::RemoveCallback(std::function<void(U*, V*)>* cb)
		{
			_handlers->Remove(cb);
		}

		template <class U, class V>
		void EventHandler<U, V>::Clear()
		{
			_handlers->Clear();
		}

		template <class U, class V>
		void EventHandler<U, V>::Trigger(U* sender, V* args)
		{
			if (_handlers->GetCount() > 0)
			{
				auto enu = _handlers->GetEnumerator();
				do
				{
					std::function<void(U*, V*)>* cb = enu->GetCurrent();
					cb->operator()(sender, args);
				}
				while (enu->Next());
				delete enu;
			}
		}

		template <class U, class V>
		EventHandler<U, V>::~EventHandler()
		{
			Clear();
			delete _handlers;
		}
	}
}

namespace std
{
	__attribute__((weak))

	void __throw_bad_function_call()
	{
		Serial.println("Library Exception");
		while (true) yield();
	}
}

#endif
