#pragma once
#ifndef PRINT_HEADER_H                 // حماية من التضمين المتكرر
#define PRINT_HEADER_H

#include <string>                       // تضمين string لأن التوقيع يستخدمها
using namespace std;                   // لتفادي std::

void printHeader(const string& title);  // إعلان دالة طباعة العنوان

#endif // PRINT_HEADER_H