/*
 * JoyStic.cpp
 *
 *  Created on: 26 ���. 2015 �.
 *      Author: Grigoriy
 */
#include "PultClasses.h"

JoyChannels::JoyChannels(JoyChannelIF** array, UInt32 count)
{
	if(count>channels.getMaxSize())
	{
		count=channels.getMaxSize();
	}
	for(UInt8 i=0;i!=count;i++)
	{
		channels.add(array[i]);
	}

}




