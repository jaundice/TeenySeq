// TrackControls.h

#ifndef _TRACKCONTROLS_h
#define _TRACKCONTROLS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include <Wire.h>

struct ControlValue {
	byte CCNumber;
	bool HasChanged;
	float_t Value;
};

class TrackControls {
	byte CCNumbers[12]{ 1,2,3,4,5,6,7,8,9,10 };
	String ParamNames[12];
	float_t* _previousValues[12];
	float_t* _currentValues[12];
	byte _i2cId;
	TwoWire* _wire;

public:


	TrackControls(TwoWire* wire, byte i2CId) {
		_i2cId = i2CId;
		_wire = wire;
	}

	ControlValue GetControlValue(byte index) {
		ControlValue v{
						CCNumbers[index],
						(*_currentValues)[index] ,
						!((*_currentValues)[index] == (*_previousValues)[index]) };

		return v;
	}

	void SetControl(byte index, byte CCNumber, String name) {
		CCNumbers[index] = CCNumber;
		ParamNames[index] = name;
	}

	void ReadRemote() {
		_wire->requestFrom(_i2cId, (byte)1);
	}
};

#endif

