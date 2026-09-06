#pragma once
#ifndef DELETE_MOVIE_H                 // حماية من التضمين المتكرر
#define DELETE_MOVIE_H

#include "cinema_data.h"               // استيراد الهياكل
using namespace std;                   // لتفادي std::

bool deleteMovie(vector<Movie>& movies, int movieId, const vector<Booking>& bookings); // إعلان

#endif // DELETE_MOVIE_H