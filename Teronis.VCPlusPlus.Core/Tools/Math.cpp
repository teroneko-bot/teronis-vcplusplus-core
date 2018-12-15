#include "Math.h"
#include <iostream>
#include "Integer.h"

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			int MathTools::isLeapYear(int year) {
				return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
			}

			int MathTools::calcLeapYearWeekDayIndex(int year, int day) {
				return (((day + 105 + (5 * (year - 1 - ((year - 1) / 100) * 100) / 4)) + (2 * ((year - 1) / 100)) - ((year - 1) / 400)) % 7);
			}

			string MathTools::calcLeapYearWeekDayName(int year, int day) {
				return IntegerTools::toWeekDayName(calcLeapYearWeekDayIndex(day, year));
			}
		};
	}
}