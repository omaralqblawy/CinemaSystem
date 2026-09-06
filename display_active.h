#pragma once
#ifndef DISPLAY_ACTIVE_H               // حماية من التضمين المتكرر
#define DISPLAY_ACTIVE_H

#include "cinema_data.h"               // استيراد هياكل البيانات
using namespace std;                   // لتفادي كتابة std::

void displayActiveMovies(const vector<Movie>& movies); // إعلان الدالة

#endif // DISPLAY_ACTIVE_H