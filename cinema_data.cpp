#include "cinema_data.h"              // تضمين هيدر التعاريف
             // لتفادي كتابة std:: في كل سطر

// تعريف قائمة الصالات الافتراضية
 const std:: vector<Hall> halls = {
    {1, "Main Hall", ROWS_DEFAULT, COLS_DEFAULT, false}, // صالة رئيسية افتراضية
    {2, "VIP Hall", 5, 8, true}                         // صالة VIP افتراضية
};

// تعريف قائمة الأفلام الابتدائية (مثال)
 const std:: vector<Movie> movies = {
    {100, "Inception", "Sci-Fi", "18:30", 5.5, 1, "Now Showing",
        vector<vector<char>>(ROWS_DEFAULT, vector<char>(COLS_DEFAULT, 'O'))} // مقاعد مهيأة
};

// تعريف قائمة الحجوزات فارغة كبدايةاً
 namespace {
    // NOSONAR
    std::vector<Booking> bookings = {};
    
    // NOSONAR
    int nextBookingId = STARTING_BOOKING_ID; // تهيئة معرف الحجز التالي
}
