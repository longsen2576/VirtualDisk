/******************************************
*Author:longsen
*Date:2017-5-5
*File:VirtualDisk.c
*******************************************/

#include <ntddk.h>

#include "VitualDisk.h"
#include "CommonDef.h"
#include "VdHandler.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT driver_obj, PUNICODE_STRING reg_path)
{
	UNREFERENCED_PARAMETER(driver_obj);
	UNREFERENCED_PARAMETER(reg_path);
	//force to insert a break point 
	DbgBreakPoint();

	DbgPrint("Driver load");
	NTSTATUS status = STATUS_SUCCESS;
	
	/*driver_obj->DriverExtension->AddDevice = VdAddDevice;
	driver_obj->DriverUnload = DriverUnload;

	driver_obj->MajorFunction[IRP_MJ_DEVICE_CONTROL] = VdDefaultDispatchRoutine;
	driver_obj->MajorFunction[IRP_MJ_READ] = VdDefaultDispatchRoutine;
	driver_obj->MajorFunction[IRP_MJ_WRITE] = VdDefaultDispatchRoutine;*/
	
	return status;
}


VOID DriverUnload(PDRIVER_OBJECT driver_obj)
{
	UNREFERENCED_PARAMETER(driver_obj);
	DbgPrint("Driver unload");
}

