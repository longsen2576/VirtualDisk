/******************************************
*Author:longsen
*Date:2017-5-5
*File:VdHandler.h
*******************************************/

#pragma once

#include <ntddk.h>

NTSTATUS VdAddDevice(PDRIVER_OBJECT DriverObject, PDEVICE_OBJECT PhysicalDeviceObject);
NTSTATUS VdRemoveDevice(PDEVICE_EXTENSION pdx, PIRP Irp);

NTSTATUS VdDefualtDispatchRoutine(PDEVICE_OBJECT fdo, PIRP Irp);
NTSTATUS VdDefaultPnpHandler(PDEVICE_EXTENSION pdx, PIRP Irp);
