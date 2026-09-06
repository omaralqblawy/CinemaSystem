#pragma once
#ifndef UPDATE_STATUS_H                // حماية من التضمين المتكرر
#define UPDATE_STATUS_H

#include "cinema_data.h"               // استيراد الهياكل
using namespace std;                   // لتفادي std::

void updateMovieStatus(vector<Movie>& movies, int movieId, const string& newStatus); // إعلان

#endif // UPDATE_STATUS_H