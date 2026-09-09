#include "clear_screen.h"
#include <iostream>

void clearScreen() {
#ifdef _WIN32
    system("cls");                     // ويندوز
#else
    std::cout << "\033[2J\033[H";      // لينكس وماك
#endif
}
