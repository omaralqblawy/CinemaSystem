#pragma once
#ifndef FIND_HALL_H
#define FIND_HALL_H

#include "cinema_data.h"            // استيراد تعريف Hall و vector
using namespace std;               // حسب طلبك

// نسخة للقراءة: تعيد مؤشر ثابت إلى Hall أو nullptr إن لم توجد
const Hall* findHallById(const vector<Hall>& halls, int hallId);

// نسخة للتعديل: تعيد مؤشر قابل للتعديل إلى Hall أو nullptr إن لم توجد
Hall* findHallById(vector<Hall>& halls, int hallId);

#endif // FIND_HALL_H