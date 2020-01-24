// 
// 
// 

#include "TrackControls.h"

void TrackControls::ReadRemote()
{
	_wire->requestFrom(_i2cId, static_cast<byte>(1));
}
