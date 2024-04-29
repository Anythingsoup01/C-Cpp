#include "Core.h"

#include <math.h>
#include <string>

struct ChageDelimiter : std::ctype<char> {
	ChageDelimiter()
		: std::ctype<char>(CreateTable()) {}
	static mask const* CreateTable() {
		static mask sMask[table_size];
		sMask['\n'] = ctype_base::space;
		return sMask;
	}
};

Components Core::GetComponents(std::string input)
{
	const char* Variable = input.c_str();

	std::string num1;
	std::string num2;
	std::string opperator;

	bool firstSpace = false;
	bool secondSpace = false;

	for (int i = 0; i < strlen(Variable); i++) {
		if (!firstSpace) {
			if (Variable[i] != ' ') {
				num1 += Variable[i];
			}
			else firstSpace = true;
		}
		else if (firstSpace && !secondSpace) {
			if (Variable[i] != ' ') {
				opperator += Variable[i];
			}
			else secondSpace = true;
		}
		else if (firstSpace && secondSpace) {
			if (Variable[i] != ' ') {
				num2 += Variable[i];
			}
		}
	}

	if (num2 != "") {
		return Components{ std::stof(num1), std::stof(num2), opperator };
	}
	else {
		return Components{ std::stof(num1), 0, opperator };
	}

	
}

std::string Core::GetResults()
{
	std::cin.imbue(std::locale(std::cin.getloc(), new ChageDelimiter));

	std::string input;
	std::cin >> input;

	Components Vars = GetComponents(input);


	float Result = GetOpperation(Vars.num1, Vars.num2, Vars.opperation);
	return std::to_string(Result);
}

float Core::GetOpperation(float num1, float num2, std::string opperation)
{
	switch (*opperation.c_str())
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	case '%':
		return (int)num1 % (int)num2;
	case '2':
		return sqrt(num1);
	case '3':
		return cbrt(num1);
	}
	

	return 0;
}
