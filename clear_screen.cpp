#include "clear_screen.h"               // تضمين الهيدر
#include <iostream>                     // تضمين للإخراج

// تنفيذ دالة مسح شاشة الكونسول
void clearScreen() {
#ifdef _WIN32
    system("cls");                     // استخدام الأمر cls على ويندوز
#else
    cout << "\x1B[2J\x1B[H";           // إرسال تسلسل ANSI لمسح الشاشة على UNIX-like
#endif
}