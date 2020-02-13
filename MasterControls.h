// MasterControls.h

#ifndef _MASTERCONTROLS_h
#define _MASTERCONTROLS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#define NEOPIXWIRE &Wire2
#include <seesaw_neopixel.h>
#include <Adafruit_NeoTrellis.h>
#include <Wire.h>

class MasterControls
{
	Adafruit_NeoTrellis _buttons = Adafruit_NeoTrellis(23, NEOPIXWIRE);

public :
	MasterControls()
	{
	}
};


#endif
