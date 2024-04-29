#include "core/core.h"

int main(void) {

	while (true) {
		std::string var = Core::ToFloat();
		std::cout << var << std::endl;
	}
}