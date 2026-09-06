#include "delete_movie.h"               // تضمين الهيدر
#include <iostream>                     // تضمين للإخراج
#include <algorithm>                    // تضمين للبحث والحذف

// تنفيذ دالة حذف الفيلم إذا لم يكن عليه حجوزات نشطة
bool deleteMovie(vector<Movie>& movies, int movieId, const vector<Booking>& bookings) {
    for (const auto& b : bookings) {   // التحقق من وجود حجوزات متعلقة بالفيلم
        if (b.movieId == movieId && b.isActive) { // إن وُجد حجز نشط
            cout << "Cannot delete movie " << movieId << ": active bookings exist.\n"; // منع الحذف
            return false;              // إرجاع false
        }
    }
    auto it = find_if(movies.begin(), movies.end(), [&](const Movie& m) { return m.movieId == movieId; }); // إيجاد الفيلم
    if (it == movies.end()) {           // إن لم يوجد الفيلم
        cout << "Movie not found\n";    // إخطار
        return false;                   // إرجاع false
    }
    movies.erase(it);                   // حذف الفيلم من القائمة
    cout << "Movie " << movieId << " deleted successfully.\n"; // إخطار النجاح
    return true;                        // إرجاع true
}