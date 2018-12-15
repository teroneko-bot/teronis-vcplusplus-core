#include "Character.h"
#include <iostream>
#include "Integer.h"

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			int CharacterTools::toNumber(char c) {
				return (int)c - (char)'0';
			}
			
			int CharacterTools::searchCharacter(char* ptr, int n, char c, int startIndex, int endIndex) {
				IntegerTools::initializeEndIndex(n, startIndex, &endIndex);

				for (int i = startIndex; i < n; i++)
					if (*(ptr + i) == c)
						return i;

				return -1;
			}

			int CharacterTools::transformCharsToNumber(char* ptr, int n, int startIndex, int backIndex) {
				IntegerTools::initializeEndIndex(n, startIndex, &backIndex);

				int mSize = sizeof(ptr), indexRange = backIndex - startIndex + 1, j = 0;

				// Now we need the 0-index jBackIndex.
				for (backIndex; backIndex >= startIndex; backIndex--) {
					int temp = indexRange - (backIndex - startIndex + 1);
					int n = toNumber(*(ptr + backIndex));
					int multiplier = (int)pow(10, temp);
					n *= multiplier;
					j += n;
				}

				return j;
			}
		};
	}
}