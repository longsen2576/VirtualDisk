/******************************************
*Author:longsen
*Date:2017-5-5
*File:VdHandler.c
*******************************************/

#include "VdHandler.h"
#include "CommonDef.h"

NTSTATUS VdDefaultDispatchRoutine(PDEVICE_OBJECT fdo, PIRP irp)
{
	UNREFERENCED_PARAMETER(fdo);

	DbgPrint("Enter default dispatch routine");

	NTSTATUS status = STATUS_SUCCESS;	

	irp->IoStatus.Status = STATUS_SUCCESS;
	irp->IoStatus.Information = 0;
	IoCompleteRequest(irp, IO_NO_INCREMENT);

	return status;
}

NTSTATUS VdAddDevice(PDRIVER_OBJECT driver_obj, PDEVICE_OBJECT phy_dev_obj)
{
	DbgPrint("Enter add device");

	NTSTATUS status = STATUS_SUCCESS;
	PDEVICE_OBJECT fdo = NULL;
	PDEVICE_EXTENSION pdx = NULL;
	UNICODE_STRING dev_name;
	UNICODE_STRING sym_name;

	RtlInitUnicodeString(&dev_name, VD_DEV_NAME);
	RtlInitUnicodeString(&sym_name, VD_DEV_DOS_NAME);

	status = IoCreateDevice(driver_obj,
		sizeof(DEVICE_EXTENSION),
		&dev_name,
		FILE_DEVICE_UNKNOWN,
		0,
		FALSE,
		&fdo);
	if (STATUS_SUCCESS!=status)
	{
		return status;
	}
	pdx = (PDEVICE_EXTENSION)fdo->DeviceExtension;
	pdx->fdo = fdo;
	pdx->dev_nam = dev_name;
	pdx->sym_name = sym_name;
	pdx->next_stack_dev = NULL;
	pdx->next_stack_dev = IoAttachDeviceToDeviceStack(fdo, phy_dev_obj);

	status = IoCreateSymbolicLink(&sym_name, &dev_name);
	if (STATUS_SUCCESS!=status)
	{
		IoDeleteSymbolicLink(&sym_name);
		status = IoCreateSymbolicLink(&sym_name, &dev_name);
		if (STATUS_SUCCESS!=status)
		{
			IoDeleteDevice(fdo);
			return status;
		}
	}
	fdo->Flags |= DO_BUFFERED_IO | DO_POWER_PAGABLE;
	fdo->Flags &= ~DO_DEVICE_INITIALIZING;

	return status;
}

NTSTATUS VdRemoveDevice(PDEVICE_EXTENSION pdx, PIRP irp)
{
	DbgPrint("enter remove device");

	NTSTATUS status = STATUS_SUCCESS;
	
	irp->IoStatus.Status = STATUS_SUCCESS;

	status=IoDeleteSymbolicLink(&pdx->sym_name);
	if (NULL!=pdx->next_stack_dev)
	{
		IoDeleteDevice(pdx->next_stack_dev);
	}
	IoDeleteDevice(pdx->fdo);

	return status;
}

