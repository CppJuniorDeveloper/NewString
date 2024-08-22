#include <iostream>
#include "NEWSTR.h"

int main() {
	setlocale(LC_ALL, "ru");
	NEWSTR nstr{"qq"};
	const char* n{ "qqq" };
	NEWSTR nn{ "qqq" };
	std::string nnn{ "qqq" };
}