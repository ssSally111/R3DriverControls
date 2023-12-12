#include <windows.h>
#include <iostream>

#define DRIVER_NAME L"\\\\.\\DriverControlsTest"

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

	UCHAR buff[10];
	ULONG ulRead;
	if (ReadFile(hDevice, buff, 10, &ulRead, NULL))
	{
		std::cout << "read length:" << ulRead << std::endl;
		for (int i = 0; i < (int)ulRead; i++)
		{
			std::cout << std::hex << (int)buff[i] << " ";
		}
	}

	CloseHandle(hDevice);
	return 0;
}