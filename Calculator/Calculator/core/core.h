#pragma once
#include <iostream>

struct Output {
	float num1, num2;
	std::string opperation;
};

class Core {
public:
	static Output GetSegments(std::string input);
	static std::string ToFloat();

	static float Calculate(float num1, float num2, std::string opperation);
private:

};