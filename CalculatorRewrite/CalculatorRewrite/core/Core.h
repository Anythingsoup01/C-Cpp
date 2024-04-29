#pragma once

#include <iostream>

struct Components {
	float num1, num2;
	std::string opperation;
};

class Core
{
public:
	static Components GetComponents(std::string input);
	static std::string GetResults();
	static float GetOpperation(float num1, float num2, std::string opperation);
};

