#include "Integer.h"
#include <iostream>

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			// It only initializes an end index properly.
			void IntegerTools::initializeEndIndex(int stringLength, int startIndex, int* endIndex) {
				if (-1 == startIndex)
					*endIndex = stringLength - 1;
			}
		};
	}
}