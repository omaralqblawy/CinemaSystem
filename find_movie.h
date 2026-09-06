#pragma once
#ifndef FIND_MOVIE_H                   // حماية من التضمين المتكرر
#define FIND_MOVIE_H

#include "cinema_data.h"               // استيراد الهياكل
using namespace std;                   // لتفادي std::

const Movie* findMovieById(const vector<Movie>& movies, int movieId); // نسخة للقراءة
Movie* findMovieById(vector<Movie>& movies, int movieId);             // نسخة للتعديل

#endif // FIND_MOVIE_H