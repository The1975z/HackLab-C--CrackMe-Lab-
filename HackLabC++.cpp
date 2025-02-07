
#include <iostream>
#include <windows.h>
#include <winternl.h>
#include <process.h>
#include <tlhelp32.h>
#include <inttypes.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <d3d9.h>
#include <dwmapi.h>
#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <Mmsystem.h>
#include <mciapi.h>
#include <shobjidl_core.h>
#include <direct.h>
#include <urlmon.h>
#include <random>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <winioctl.h>
#include <random>
#include <msxml.h>
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <vector>
#include <random>
#include <memoryapi.h>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include <string_view>
#include <mutex>
#include <chrono>
#include <TlHelp32.h>
#include <Psapi.h>
#include <tchar.h>
#include <winioctl.h>
#include <Uxtheme.h>
#include <dwmapi.h>
#include <WinInet.h>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <vector>
#include <vector>
#include <math.h>
#include <windows.h>
#include <Lmcons.h>
#include <vector>
#include <random>


using namespace std;

void displayAnimatedLoadingBar(string message, int steps = 30) {
    cout << message << endl;
    const char animation[] = { '|', '/', '-', '\\' };
    for (int i = 0; i <= steps; i++) {
        cout << "\r[";
        for (int j = 0; j < steps; j++) {
            if (j < i)
                cout << "=";
            else
                cout << " ";
        }
        cout << "] " << (i * 100 / steps) << "% " << animation[i % 4];
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << endl;
}
void logoutSystem(bool& keepRunning) {
    int choice;
    cout << "\nDo you want to log out? (1 = Yes, 0 = No): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Logging out..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        keepRunning = true;
    }
    else {
        cout << "Thank you for using the system!" << endl;
        keepRunning = false; 
    }
}

int main() 
{
    /*VIRTUALIZERSTART*/
    const char* correctUsername = "admin";
    const char* correctPassword = "1234";
    const char* correctKey = "ABCD";
    char username[32];
    char password[32];
    char key[16];

    bool keepRunning = true;

    while (keepRunning) 
    {
        int attempts = 3;

        while (attempts > 0) 
        {
            cout << "\n========================================" << endl;
            cout << "       Welcome to Secure Login System   " << endl;
            cout << "========================================" << endl;
            cout << "\nAttempts remaining: " << attempts << endl;

            cout << "\nEnter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            cout << "Enter Key: ";
            cin >> key;

            displayAnimatedLoadingBar("Verifying credentials, please wait...", 30);

            if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0 && strcmp(key, correctKey) == 0)
            {
                MessageBox(NULL, TEXT("Login Successful! Welcome!"), TEXT("Login Status"), MB_OK | MB_ICONINFORMATION);
                logoutSystem(keepRunning);
                break;
            }
            else 
            {
                system("cls");
                cout << "\n❌ Invalid credentials." << endl;
                attempts--;
            }
        }
        if (attempts == 0) {
            cout << "\nYou have been locked out of the system!" << endl;
            keepRunning = false;
        }
    }
    /*VIRTUALIZEREND*/
    return 0;
}
