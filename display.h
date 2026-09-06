#pragma once
#ifndef DISPLAY_ALL_H                  // حماية من التضمين المتكرر
#define DISPLAY_ALL_H

#include "cinema_data.h"               // استيراد هياكل البيانات
using namespace std;                   // لتفادي كتابة std::

void displayAllMovies(const vector<Movie>& movies); // إعلان الدالة

#endif // DISPLAY_ALL_H