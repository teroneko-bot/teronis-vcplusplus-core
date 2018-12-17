#include "Date.h"
#include <iostream>
#include "Integer.h"

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			const int MONTH_DAYS[] = { 31,59,90,120,151,181,212,243,273,304,334,365 };

			int getMonthCode(int month) {
				return month == 1 ? 0 : MONTH_DAYS[month - 2];
			}

			int getYearCode(int year) {
				return year + (int)floor(year / (double)4);
			}

			int getCenturyCode(int century) {
				return (3 - (century % 4)) * 2;
			}

			// A year is a leap year, if the year can be divided by 4 but not by 100.
			// But it is also a leap year if the year can be divided by 400.
			bool DateTools::isLeapYear(int year) {
				return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
			}

			int getLeapYearCorrectionDay(int year) {
				return DateTools::isLeapYear(year) ? 1 : 0;
			}

			int calcLeapYearWeekDayIndexUnchecked(int year, int month, int day) {
				return (day + getMonthCode(month) + getYearCode(year % 100) + getCenturyCode((int)floor(year / (double)100)) - getLeapYearCorrectionDay(year)) % 7;
			}

			// The explanation to this formula can be read at https://de.wikipedia.org/wiki/Wochentagsberechnung.
			int DateTools::calcLeapYearWeekDayIndex(int year, int month, int day) {
				month = ((month - 1) % 12) + 1;
				return calcLeapYearWeekDayIndexUnchecked(year, month, day);
			}

			// It expects a non-leap-year-day.
			int getMonth(int day) {
				if (day > 365)
					return 12;

				for (int i = 0; i < 12; i++) {
					// If the total month days are greater than day,
					// then day is during the month i + 1.
					if (MONTH_DAYS[i] >= day)
						return i + 1;
				}

				// The return value will be implicitly zero.
				// But this function won't reach this point at anytime.
			}

			// It moves a day one day in the past, if the year is a leap year.
			int normalizePossibleLeapYearDay(int year, int day) {
				// If the year is a leap year and the day is the 29. february or later, ...
				if (DateTools::isLeapYear(year) && day > MONTH_DAYS[1])
					// ... then move it.
					day--;

				return day;
			}

			int getMonth(int day, int year) {
				// When your day is the 29. february 2000 and the year is a leap year, your day would nevertheless fall into a march.
				// To prevent this, we normalize day to get the correct month index.
				day = normalizePossibleLeapYearDay(year, day);
				// As the day is now normalized, we can determine the month index and return it.
				return getMonth(day);
			}

			int DateTools::calcLeapYearWeekDayIndex(int year, int days) {
				// The solution by PES-paper:
				//return (((day + 105 + (5 * (year - 1 - ((year - 1) / 100) * 100) / 4)) + (2 * ((year - 1) / 100)) - ((year - 1) / 400)) % 7);

				/* "My" solution: */
				// This ensures a valid day.
				days = ((days - 1) % 366) + 1;
				int month = getMonth(days, year);
				/* Now we don not need the year days, but the month days. */
				int totalMonthDays = MONTH_DAYS[month - 1];
				days = totalMonthDays - MONTH_DAYS[month - 2] - (totalMonthDays - days);
				// Return the calucalated index.
				return calcLeapYearWeekDayIndexUnchecked(year, month, days);
				// PS: "" because I am not the inventor of the formula. ^^
			}

			// A number from 0-6 represents the literal week day where 0 is sunday.
			string DateTools::toWeekDayName(int day) {
				// By this we do not have to define a default return value.
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