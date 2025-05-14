#include <iostream>
#include <chrono>
#include <thread>

int main() {
	// Usando endl (flush automático)
	std::cout << "Usando endl:" << std::endl;
	for (int i = 1; i <= 3; i++) {
		std::cout << "Mensaje " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1)); // Espera 1 segundo
	}
	// Usando \n (sin flush)
	std::cout << "\nUsando \\n:\n";
	for (int i = 1; i <= 3; i++) {
		std::cout << "Mensaje " << i << "\n";
		std::this_thread::sleep_for(std::chrono::seconds(1)); // Espera 1 segundo
	}
	return (0);
}