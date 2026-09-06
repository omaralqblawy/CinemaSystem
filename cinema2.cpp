// cinema2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>                     // تضمين للإدخال/الإخراج
#include <limits>                       // تضمين لتنظيف باف الإدخال
#include "cinema_data.h"                // تضمين هياكل البيانات والتعريفات
#include "add_new_movie.h"              // تضمين دوال الإضافة
#include "display.h"                // تضمين دوال العرض
#include "display_active.h"
#include "find_movie.h"                
#include "update_price.h"
#include "update_status.h"
#include "delete_movie.h"
#include "press_enter.h"
#include "clear_screen.h"
#include "print_header.h"                                                 //
#include "find_hall.h"   // إعلان findHallById (const و non-const)
using namespace std;                   // لتفادي std:: داخل main

int main() {
    printHeader("Cinema Manager");      // طباعة عنوان البرنامج

    while (true) {                      // حلقة القائمة الرئيسية
        cout << "1) Add new movie\n2) List all movies\n3) List Now Showing\n4) Update price\n5) Update status\n6) Delete movie\n7) Quit\nChoose: "; // طباعة الخيارات
        int choice;                     // متغير لاختيار المستخدم
        if (!(cin >> choice)) break;    // قراءة الاختيار وإنهاء لو فشل الإدخال
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تنظيف نهاية السطر

        if (choice == 1) {
            addNewMovie(movies, halls); // استدعاء إضافة فيلم
            pressEnterToContinue();    // انتظار Enter
        }
        else if (choice == 2) {
            displayAllMovies(movies);  // استدعاء عرض كل الأفلام
            pressEnterToContinue();
        }
        else if (choice == 3) {
            displayActiveMovies(movies);// عرض Now Showing
            pressEnterToContinue();
        }
        else if (choice == 4) {
            cout << "Enter movie id: "; // طلب معرف الفيلم
            int id; cin >> id;          // قراءة المعرف
            cout << "Enter new price: "; // طلب السعر الجديد
            double p; cin >> p;         // قراءة السعر
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تنظيف الإدخال
            updateMoviePrice(movies, id, p); // تحديث السعر
            pressEnterToContinue();
        }
        else if (choice == 5) {
            cout << "Enter movie id: "; // طلب معرف الفيلم
            int id; cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter new status: "; // طلب الحالة الجديدة
            string s; getline(cin, s);
            updateMovieStatus(movies, id, s); // تحديث الحالة
            pressEnterToContinue();
        }
        else if (choice == 6) {
            cout << "Enter movie id: ";
            int id; cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            deleteMovie(movies, id, bookings); // محاولة الحذف
            pressEnterToContinue();
        }
        else if (choice == 7) {
            cout << "Goodbye\n";         // رسالة وداع
            break;                      // إنهاء البرنامج
        }
        else {
            cout << "Invalid choice\n"; // خيار غير صحيح
            pressEnterToContinue();
        }

        clearScreen();                  // مسح الشاشة بين التكرارات
    }
    
        printHeader("Hall Management - مثال على استخدام findHallById"); // اختياري: يتطلب print_header.h

        while (true) {
            cout << "1) عرض صالة (قراءة فقط)\n"
                << "2) تعديل صالة (تعديل)\n"
                << "3) خروج\n"
                << "اختر: ";

            int choice;
            if (!(cin >> choice)) break;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // تنظيف الباف

            if (choice == 1) {
                cout << "أدخل رقم الصالة للعرض: ";
                int id;
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << "إدخال غير صالح\n";
                    continue;
                }
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

                // استخدام نسخة القراءة (const) — نمرر مرجع ثابت
                const Hall* h = findHallById(static_cast<const vector<Hall>&>(halls), id);
                if (!h) {
                    cout << "الصالة غير موجودة بالرقم " << id << "\n";
                }
                else {
                    cout << "ID: " << h->hallId
                        << " | Name: " << h->name
                        << " | Size: " << h->rows << "x" << h->cols
                        << " | VIP: " << (h->isVip ? "Yes" : "No") << "\n";
                }
            }
            else if (choice == 2) {
                cout << "أدخل رقم الصالة للتعديل: ";
                int id;
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << "إدخال غير صالح\n";
                    continue;
                }
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

                // استخدام نسخة التعديل (non-const)
                Hall* h = findHallById(halls, id);
                if (!h) {
                    cout << "الصالة غير موجودة بالرقم " << id << "\n";
                    continue;
                }

                cout << "الصالة الموجودة: " << h->name << " (" << h->rows << "x" << h->cols << ") VIP=" << (h->isVip ? "Yes" : "No") << "\n";

                cout << "أدخل اسم جديد (أو اضغط Enter للاحتفاظ): ";
                string newName;
                getline(cin, newName);
                if (!newName.empty()) h->name = newName;

                cout << "أدخل عدد الصفوف الجديد (أو 0 للاحتفاظ): ";
                string rowsLine;
                getline(cin, rowsLine);
                if (!rowsLine.empty()) {
                    int newRows = stoi(rowsLine);
                    if (newRows > 0) h->rows = newRows;
                }

                cout << "أدخل عدد الأعمدة الجديد (أو 0 للاحتفاظ): ";
                string colsLine;
                getline(cin, colsLine);
                if (!colsLine.empty()) {
                    int newCols = stoi(colsLine);
                    if (newCols > 0) h->cols = newCols;
                }

                cout << "هل هذه صالة VIP؟ (y/n/Enter للاحتفاظ): ";
                string vipLine;
                getline(cin, vipLine);
                if (!vipLine.empty()) {
                    char c = vipLine[0];
                    if (c == 'y' || c == 'Y') h->isVip = true;
                    else if (c == 'n' || c == 'N') h->isVip = false;
                }

                cout << "تم تحديث بيانات الصالة.\n";

                // ملاحظة: إن أردت إعادة تهيئة مقاعد الأفلام المرتبطة بهذه الصالة عند تغيير rows/cols
                // أستطيع أضيف لك كود هنا ليحدث كل Movie حيث movie.hallId == h->hallId.
            }
            else if (choice == 3) {
                cout << "الخروج...\n";
                break;
            }
            else {
                cout << "خيار غير صحيح\n";
            }

            cout << "\n";
        }

        
    

    return 0;                           // نهاية main
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
