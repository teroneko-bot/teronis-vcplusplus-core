#pragma once

#include <iostream>

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			class MathTools {
			public:
				static int isLeapYear(int year);
				static int calcLeapYearWeekDayIndex(int year, int day);
				static string calcLeapYearWeekDayName(int year, int day);
			};
		}
	}
}