#include "display_halls.h"          // تضمين إعلان الدالة
#include <iostream>                 // للإخراج
#include <iomanip>                  // لتنسيق العرض (setw)

void displayAllHalls(const vector<Hall>& halls) {
    if (halls.empty()) {           // إن لم توجد صالات
        std::cout << "No halls available.\n";
        return;
    }

    // طباعة رأس جدول مبسط
    std::cout << std::left << std::setw(6) << "ID"
        << std::setw(20) << "Name"
        << std::setw(8) << "Rows"
        << std::setw(8) << "Cols"
        << std::setw(6) << "VIP" << "\n";

    std::cout << std::string(48, '-') << "\n"; // فاصل

    // طباعة صف لكل صالة
    for (const auto& h : halls) {
        std::cout << std::left << std::setw(6) << h.hallId
            << std::setw(20) << h.name
            << std::setw(8) << h.rows
            << std::setw(8) << h.cols
            << std::setw(6) << (h.isVip ? "Yes" : "No") << "\n";
    }
}