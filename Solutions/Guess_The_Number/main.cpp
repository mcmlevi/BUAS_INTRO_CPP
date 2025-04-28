#include <random>
#include <print>
#include <iostream>
#include <cctype>

const int max_guesses = 5;


int generate_random_number(int min = 0, int max = 100){
	// The random device and generator should only be created once for the program.
	// Making it static enforces it gets initialize only once.
	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

void print_instructions(){
	std::print("Try to guess the number in {} guesses\n", max_guesses);
}

int get_number_from_user(){
	std::print("Please enter a number ");
	int number = 0;
	std::cin >> number;
	return number;
}

void play_game(){
	int number_to_guess = generate_random_number(0, 5);

	for (int guesses_left = max_guesses; guesses_left > 0; --guesses_left) {
		int guess = get_number_from_user();
		if (number_to_guess == guess) {
			std::print("You Won! {} is the correct number\n", guess);
			return;
		}
		else if (guess < number_to_guess){
			std::print("{} is less then the number you are trying to guess\n", guess);
		}
		else{
			std::print("{} is greater then the number you are trying to guess\n", guess);
		}
	}
	std::print("You lost! The correct number was: {}\n", number_to_guess);
}

bool keep_playing(){
	std::print("Do you want to play again? (Y/N) ");
	
	// This code will break if the user enters more then 1 character, ignored for simplicity 
	char result = ' ';
	std::cin >> result;
	
	// This is a quirk of tolower, it expect an unsigned char, so we explicitly cast to it.
	// https://en.cppreference.com/w/cpp/string/byte/tolower
	return std::tolower(static_cast<unsigned char>(result)) == 'y';
}

int main(){
	print_instructions();

	do 
	{
		play_game();
	} while (keep_playing());
}