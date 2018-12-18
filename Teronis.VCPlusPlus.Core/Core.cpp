#include <iostream>
#include <string>
#include "Core.h"

using namespace std;

namespace Teronis {
	namespace VCPlusPlus {
		namespace Tools {
			void stop(int code, string message) {
				if (!message.empty())
					cout << message << "\n";

				if (!code)
					system("pause");

				exit(code);
			}

			void stop(int code) {
				stop(code, "");
			}
		};
	}
}