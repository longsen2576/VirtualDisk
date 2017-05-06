/******************************************
*Author:longsen
*Date:2017-5-5
*File:VirtualDisk.h
*******************************************/

#pragma once

#include <ntddk.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT driver_obj, PUNICODE_STRING reg_path);

VOID DriverUnload(PDRIVER_OBJECT driver_obj);

