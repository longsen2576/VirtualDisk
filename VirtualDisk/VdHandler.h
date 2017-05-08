/******************************************
*Author:longsen
*Date:2017-5-5
*File:VdHandler.h
*******************************************/

#pragma once

#include <ntddk.h>

#include "CommonDef.h"

NTSTATUS VdAddDevice(PDRIVER_OBJECT driver_obj, PDEVICE_OBJECT phy_dev_obj);
NTSTATUS VdRemoveDevice(PDEVICE_EXTENSION pdx, PIRP irp);

NTSTATUS VdDefaultDispatchRoutine(PDEVICE_OBJECT fdo, PIRP irp);
