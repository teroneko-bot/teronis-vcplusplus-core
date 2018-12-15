#include "Integer.h"
#include <iostream>

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			// A number from 0-6 represents the literal week day where 0 is sunday.
			string IntegerTools::toWeekDayName(int day) {
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
				default:
					throw invalid_argument("bad day");
				}
			}

			// It only initializes an end index properly.
			void IntegerTools::initializeEndIndex(int stringLength, int startIndex, int* endIndex) {
				if (-1 == startIndex)
					*endIndex = stringLength - 1;
			}
		};
	}
}