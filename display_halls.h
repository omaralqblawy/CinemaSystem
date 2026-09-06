#pragma once
#ifndef DISPLAY_HALLS_H
#define DISPLAY_HALLS_H

#include "cinema_data.h"            // استيراد تعريف Hall و vector
using namespace std;               // لتفادي كتابة std::

/*
  دالة: عرض كل الصالات
  التوقيع: void (const vector<Hall>& halls)
  الهدف: طباعة جدول مبسط يوضح كل الصالات ومواصفاتها
*/
void displayAllHalls(const vector<Hall>& halls);

#endif // DISPLAY_HALLS_H