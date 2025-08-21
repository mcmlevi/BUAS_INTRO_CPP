#include <print>
#include "random_word.h"

int main() {
	std::string random_word = get_random_word();
	std::print("{}", random_word);
}