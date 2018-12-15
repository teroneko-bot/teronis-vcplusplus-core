#pragma once

#include <iostream>

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			class IntegerTools {
			public:
				static string toWeekDayName(int day);
				static void initializeEndIndex(int n, int startIndex, int* endIndex);
			};
		}
	}
}