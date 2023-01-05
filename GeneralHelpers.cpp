#include "GeneralHelpers.h"

char* GeneralHelpers::fromStringToCharArray(std::string input) {
	char char_array[200];
	strcpy(char_array, input.c_str());
	return char_array;
}

int GeneralHelpers::fromStringToInt(std::string input) {
	int number = stoi(input);
	return number;
}

std::string GeneralHelpers::fromIntToString(int input) {
	std::string temp_str = std::to_string(input);
	return temp_str;
}

char* GeneralHelpers::fromIntToCharArray(int input) {
	std::string temp_str = fromIntToString(input);
	char number_array[200];
	strcpy(number_array, temp_str.c_str());
	return number_array;
}
