/******************************************
*Author:longsen
*Date:2017-5-5
*File:CommonDef.h
*******************************************/

#pragma once

#include <ntddk.h>

#define  VD_DEV_NAME L"\\Device\\MyWDMDevice"
#define  VD_DEV_DOS_NAME L"\\DosDevices\\HelloWDM"

typedef struct _DEVICE_EXTERSION
{
	PDEVICE_OBJECT fdo;
	PDEVICE_OBJECT next_stack_dev;
	UNICODE_STRING dev_nam;     
	UNICODE_STRING sym_name;     
}DEVICE_EXTENSION, *PDEVICE_EXTENSION;

