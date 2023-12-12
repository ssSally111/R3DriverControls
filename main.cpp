#include <windows.h>
#include <iostream>
#include <winioctl.h>

#define DRIVER_NAME L"\\\\.\\DriverControlsTest"
#define IOCTL_TEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

void KernelKillProcess(HANDLE hDevice, ULONG pid)
{
	DWORD dwOpt = 0;
	UCHAR optBuff[8];
	if (DeviceIoControl(hDevice, IOCTL_TEST, &pid, sizeof(ULONG), optBuff, 8, &dwOpt, NULL))
	{
		std::cout << "IOCTL_TEST result:";
		for (int i = 0; i < (int)dwOpt; i++)
		{
			std::cout << std::hex << (int)optBuff[i];
		}
	}

	std::cout << std::endl << "KernelKillProcess PID:" << pid << std::endl;
}

int main(int argc, char* argv[])
{
	HANDLE hDevice = CreateFile(
		DRIVER_NAME,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hDevice == INVALID_HANDLE_VALUE)
	{
		std::cout << "fail device..." << std::endl;
		return 1;
	}

	//UCHAR optBuff[8];
	//ULONG ulRead;
	//if (ReadFile(hDevice, buff, 10, &ulRead, NULL))
	//{
	//	std::cout << "read length:" << ulRead << std::endl;
	//	for (int i = 0; i < (int)ulRead; i++)
	//	{
	//		std::cout << std::hex << (int)buff[i] << " ";
	//	}
	//}

	ULONG pid;
	std::cout << "please enter pid..." << std::endl;
	scanf_s("%d", &pid);
	KernelKillProcess(hDevice, pid);

	CloseHandle(hDevice);
	return 0;
}