#include <print>
#include <random>

int generate_random_number(int min = 0, int max = 100) {
	// The random device and generator should only be created once for the program.
	// Making it static enforces it gets initialize only once.
	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

int main() {
	int random_number = generate_random_number(0, 200);
	std::print("A random number {}\n", random_number);
}