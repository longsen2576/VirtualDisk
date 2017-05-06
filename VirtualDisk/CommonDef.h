/******************************************
*Author:longsen
*Date:2017-5-5
*File:CommonDef.h
*******************************************/

#pragma once

#include <ntddk.h>

typedef struct _DEVICE_EXTERSION
{
	PDEVICE_OBJECT fdo;
	PDEVICE_OBJECT NextStatckDevice;
	UNICODE_STRING ustrDeviceName;      //设备名  
	UNICODE_STRING ustrSymLinkName;     //符号链接名  
}DEVICE_EXTENSION, *PDEVICE_EXTENSION;

