#pragma once
#include <exception>
#include <cstring>
#include <windows.h> 
#include <iostream>
namespace Exceptions
{
	void logError(const char*);
	struct LogicException : public std::exception {
		char msg[100];
		LogicException() {
			strcpy(msg, "Source of error is unknown, check debugger");
		}
		LogicException(char* err) {
			strcpy(msg, err);
		}
		const char* what() const throw() {
			return "Logic error";
		};
		const char* rootOfError() {
			return msg;
		}
	};
};

