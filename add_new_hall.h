#ifndef ADD_NEW_HALL_H              // حماية من التضمين المتكرر
#define ADD_NEW_HALL_H

#include "cinema_data.h"            // استيراد هياكل Hall و vector وغيرها
           

/*
  دالة: إضافة صالة جديدة
  التوقيع: void (vector<Hall>& halls)
  الهدف: قراءة بيانات الصالة من المستخدم وإضافتها إلى المتجه
*/
void addNewHall(vector<Hall>& halls);

#endif // ADD_NEW_HALL_H#pragma once
