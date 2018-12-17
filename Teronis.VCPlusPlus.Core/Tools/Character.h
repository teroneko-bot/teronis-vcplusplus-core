#pragma once

#include <iostream>

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			class CharacterTools {
			public:
				static int toNumber(char c);
				static int searchCharacter(char* ptr, int length, char c, int startIndex = 0, int endIndex = -1);
				static int transformCharsToNumber(char* ptr, int length, int startIndex = 0, int backIndex = -1);
			};
		}
	}
}