#include <print>

int main()
{
	std::print("Starting buggy C++23 program...\n");


	for (int i = 0; i < 3; i++) {
		if (i = 3) {
			std::print("i is 3\n");
		}

		int result = 100 / (i - i);
		std::print("Result is {}\n", result);
	}

	int sum;
	for (int j = 1; j < 4; j++) {
		sum += j;
	}
	std::print("Sum is: {}\n", sum);

	return 0;
}