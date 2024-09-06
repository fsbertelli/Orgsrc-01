#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void printPanel() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "+------------------------------------------------------------------+\n";
    cout << "|               * OrgsXterm Professional Edition v24.1 *           |\n";
    cout << "|               (SSH client, X server and network tools)           |\n";
    cout << "|                                                                  |\n";
    cout << "| >> SSH session to admin@15.169.126.122                           |\n";
    cout << "|    - Direct SSH      :  [OK]                                     |\n";
    cout << "|    - SSH compression :  [OK]                                     |\n";
    cout << "|    - SSH-browser     :  [OK]                                     |\n";
    cout << "|    - X11-forwarding  :  [OK]  (remote display is forwarded)      |\n";
    cout << "|                                                                  |\n";
    cout << "| >> For more info, ctrl+click on help or visit our website.       |\n";
    cout << "+------------------------------------------------------------------+\n";
}

int header() {
    printPanel();
    return 0;
}
#pragma once
