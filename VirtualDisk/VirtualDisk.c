/******************************************
*Author:longsen
*Date:2017-5-5
*File:VirtualDisk.c
*******************************************/

#include <ntddk.h>

#include "VitualDisk.h"
#include "CommonDef.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT driver_obj, PUNICODE_STRING reg_path)
{
	UNREFERENCED_PARAMETER(driver_obj);
	UNREFERENCED_PARAMETER(reg_path);
	//force to insert a break point 
	DbgBreakPoint();

	NTSTATUS status = STATUS_SUCCESS;
	DbgPrint("Driver load");
	DbgPrint("just for test driver install ");

	return status;
}


VOID DriverUnload(PDRIVER_OBJECT driver_obj)
{
	UNREFERENCED_PARAMETER(driver_obj);
	DbgPrint("Driver unload");
}

