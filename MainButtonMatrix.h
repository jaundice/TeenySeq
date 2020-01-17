// MainButtonMatrix.h

#ifndef _MAINBUTTONMATRIX_h
#define _MAINBUTTONMATRIX_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#define NEOPIXWIRE &Wire2

#include <Adafruit_NeoTrellis.h>
#include <Wire.h>
namespace ByteFarm {
	namespace TeenySeq {
		namespace UI {
			class MainButtonMatrix {

				Adafruit_NeoTrellis _trellis[3][4] = {
					{Adafruit_NeoTrellis(1,NEOPIXWIRE),Adafruit_NeoTrellis(2,NEOPIXWIRE),Adafruit_NeoTrellis(3,NEOPIXWIRE),Adafruit_NeoTrellis(4,NEOPIXWIRE)},
					{Adafruit_NeoTrellis(5,NEOPIXWIRE),Adafruit_NeoTrellis(6,NEOPIXWIRE),Adafruit_NeoTrellis(7,NEOPIXWIRE),Adafruit_NeoTrellis(8,NEOPIXWIRE)},
					{Adafruit_NeoTrellis(9,NEOPIXWIRE),Adafruit_NeoTrellis(10,NEOPIXWIRE),Adafruit_NeoTrellis(11,NEOPIXWIRE),Adafruit_NeoTrellis(12,NEOPIXWIRE)}
				};
				Adafruit_MultiTrellis _multi = Adafruit_MultiTrellis((Adafruit_NeoTrellis*)_trellis, 3, 4);
			public:
				MainButtonMatrix() {
					//_multi = new Adafruit_MultiTrellis((Adafruit_NeoTrellis*)_trellis, 3, 4);

				}
			};
		}
	}
}

#endif

