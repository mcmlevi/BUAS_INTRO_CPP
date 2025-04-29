#include <print>
int main(){
	for (int i = 99; i > 0; --i) {
		if (i == 1){
			std::print("1 bottle of beer on the wall, 1 bottle of beer.\n");
		}
		else{
			std::print("{0} bottle of beer on the wall, {0} bottle of beer.\n", i);
		}

		if (i - 1 == 0) {
			std::print("Take one down & pass it around, now there's no more bottles of beer on the wall!\n");
		}
		else {
			std::print("Take one down & pass it around, now there's {} bottles of beer on the wall\n", i - 1);
		}

	}
}