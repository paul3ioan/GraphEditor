#include "LogicException.h"
void Exceptions::logError(const char* msg) {
	// changes the color of output to blue
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	//
	std::cout << '\n' << "Logic Error: ";

	// changes the color of output to green
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_INTENSITY);
	//
	std::cout << msg << '\n' << '\n';

	// changes the color of output back to white
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	//
}