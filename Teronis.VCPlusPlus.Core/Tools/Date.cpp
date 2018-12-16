#include "Date.h"
#include <iostream>
#include "Integer.h"

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			const int MONTH_DAYS[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

			int getMonthCode(int month) {
				int monthCode = 0;

				for (--month; month >= 0; month--)
					monthCode += MONTH_DAYS[month];

				return monthCode;
			}

			int getYearCode(int year) {
				return year + (int)floor(year / (double)4);
			}

			int getCenturyCode(int century) {
				return (3 - (century % 4)) * 2;
			}

			bool DateTools::isLeapYear(int year) {
				return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
			}

			int getLeapYearCorrection(int year) {
				return DateTools::isLeapYear(year) ? -1 : 0;
			}

			int DateTools::calcLeapYearWeekDayIndex(int year, int month, int day) {
				// The solution by PES-paper:
				//return (((day + 105 + (5 * (year - 1 - ((year - 1) / 100) * 100) / 4)) + (2 * ((year - 1) / 100)) - ((year - 1) / 400)) % 7);

				// "My" solution:
				return (day + getMonthCode(month) + getYearCode(year % 100) + getCenturyCode((int)floor(year / (double)100)) - getLeapYearCorrection(year)) % 7;
			}

			int getMonth(int day) {
				// This ensures valid day input.
				day = ((day - 1) % 365) + 1;
				int totalMonthDays = 0;

				for (int i = 0; i < 12; i++) {
					totalMonthDays += MONTH_DAYS[i];

					// If the total month days are greater than day,
					// then day is during the month i + 1.
					if (totalMonthDays >= day)
						return i + 1;
				}

				// The return value will be implicitly zero.
				// But this function won't reach this point at anytime.
			}

			// It expects a day, with the consideration of an possible leap year.
			// When your day is the 1. march 2000, 
			// then your day is not 31 + 28 + 1,
			// but 31 + 29 + 1.
			int getMonth(int day, int year) {
				// If it is a leap year and the day is after the 29. february, ...
				if (DateTools::isLeapYear(year) && day > MONTH_DAYS[0] + MONTH_DAYS[1] + 1)
					// ... then normalize it.
					day--;

				return getMonth(day);
			}

			int DateTools::calcLeapYearWeekDayIndex(int year, int day) {
				return DateTools::calcLeapYearWeekDayIndex(year, getMonth(day, year), day);
			}

			// A number from 0-6 represents the literal week day where 0 is sunday.
			string DateTools::toWeekDayName(int day) {
				day = day % 7;

				switch (day) {
				case 0:
					return "Sunday";
				case 1:
					return "Monday";
				case 2:
					return "Tuesday";
				case 3:
					return "Wednesday";
				case 4:
					return "Thursday";
				case 5:
					return "Friday";
				case 6:
					return "Saturday";
				}
			}
		};
	}
}