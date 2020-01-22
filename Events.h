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

namespace ByteFarm
{
	namespace Events
	{
		using namespace DataStructures;

		template <class U, class V>
		class EventHandler
		{
		public:
			typedef void (*Callback)(U*, V*);
		protected:
			LinkedList<Callback> _handlers = LinkedList<Callback>();


		public:
			EventHandler()
			{
			};

			void RegisterCallback(Callback cb)
			{
				_handlers.Insert(cb);
			};

			void RemoveCallback(Callback cb)
			{
				_handlers.Remove(cb);
			};

			void Clear()
			{
				_handlers.Clear();
			};

			void Trigger(U* sender, V* args)
			{
				if (_handlers.GetCount() > 0)
				{
					auto enu = _handlers.GetEnumerator();
					do
					{
						enu.GetCurrent()(sender, args);
					}
					while (enu.Next());
					delete enu;
				}
			};

			virtual ~EventHandler()
			{
				Clear();
			};
		};
	}
}

#endif
