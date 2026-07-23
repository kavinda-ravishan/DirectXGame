#include <iostream>
#include "DX3D/All.h"

int main() {

	try {
		dx3d::Game game{};
		game.Run();
	} catch (const std::runtime_error& e) {
		std::cerr << "Runtime Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	} catch (...) {
		std::cerr << "Unknown exception occurred." << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
