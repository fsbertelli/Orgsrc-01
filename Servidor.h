#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void printServidor() {
    system("cls");
    cout << "Welcome to Ubuntu 18.04.6 LTS (GNU/Linux 4.9.140-tegra aarch64)\n\n";
    cout << " * Documentation:  https://help.ubuntu.com\n";
    cout << " * Management:     https://landscape.canonical.com\n";
    cout << " * Support:        https://ubuntu.com/advantage\n";
    cout << "This system has been minimized by removing packages and content that are\n";
    cout << "not required on a system that users do not log into.\n\n";
    cout << "To restore this content, you can run the 'unminimize' command.\n\n";
    cout << "432 updates can be applied immediately.\n";
    cout << "248 of these updates are standard security updates.\n";
    cout << "To see these additional updates run: apt list --upgradable\n\n";
    cout << "  Estou no Servidor! \n";



    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm local_tm;
    localtime_s(&local_tm, &now_c);
    cout << "\nLast login: " << put_time(&local_tm, "%a %b %d %H:%M:%S %Y") << " from 127.0.0.1\n";
}