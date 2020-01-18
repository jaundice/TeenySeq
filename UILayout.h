// UILayout.h

#ifndef _UILAYOUT_h
#define _UILAYOUT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
namespace ByteFarm {
	namespace TeenySeq {
		namespace UI
		{

			class UILayoutBase {

			public:
				virtual void Wire() = 0;
				virtual void Unwire() = 0;
			};


			template <class T>
			class UILayout :public UILayoutBase {
				T* Model;

				virtual void UnwireModel(T* model) = 0;
				virtual void WireModel(T* model) = 0;

			public:
				virtual void SetModel(T* model) {
					if (!(Model == nullptr))
					{
						UnwireModel(Model);
					}
					Model = model;
					WireModel(model);
				};
			};

		}
	}
}
#endif

