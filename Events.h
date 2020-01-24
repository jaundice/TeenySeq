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
#include "CallbackWrapper.h"

namespace ByteFarm
{
	namespace Events
	{
		using namespace DataStructures;

		template <class U, class V>
		class EventHandler
		{
		protected:
			LinkedList<CallbackWrapper<U, V>>* _handlers;

		public:
			EventHandler();;

			void RegisterCallback(CallbackWrapper<U, V>* cb);;

			void RemoveCallback(CallbackWrapper<U, V>* cb);;

			void Clear();;

			void Trigger(U* sender, V* args);;

			virtual ~EventHandler();;
		};

		template <class U, class V>
		EventHandler<U, V>::EventHandler()
		{
			_handlers = new LinkedList<CallbackWrapper<U, V>>();
		}

		template <class U, class V>
		void EventHandler<U, V>::RegisterCallback(CallbackWrapper<U, V>* cb)
		{
			_handlers->Insert(cb);
		}

		template <class U, class V>
		void EventHandler<U, V>::RemoveCallback(CallbackWrapper<U, V>* cb)
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
					CallbackWrapper<U, V>* cb = ((enu->GetCurrent()));
					cb->Call(sender, args);
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

#endif
