#pragma once

#include <iostream>

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			class DateTools {
			public:
				static bool isLeapYear(int year);
				static int calcLeapYearWeekDayIndex(int year, int day);
				static int calcLeapYearWeekDayIndex(int year, int month, int day);
				static string toWeekDayName(int day);
			};
		}
	}
}