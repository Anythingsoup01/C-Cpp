#include "core.h"

#include <string>


struct ChangeDelimiter : std::ctype<char> 
{
    ChangeDelimiter()
        : std::ctype<char>(
            CreateTable()) {}
    static mask const* CreateTable()
    {
        static mask
            sMask[table_size];
        sMask['\n']
            = ctype_base::space;
        return sMask;
    }
};

Output Core::GetSegments(std::string input) 
{
    const char* variables = input.c_str();

    std::string str1;
    std::string str2;
    std::string opp;

    bool firstSpace = false;
    bool secondSpace = false;

    for (int i = 0; i < strlen(variables); i++) {
        if (!firstSpace) {
            if (variables[i] != ' ')
            {
                str1 += variables[i];
            }
            else firstSpace = true;
        }
        else if (firstSpace && !secondSpace) {
            if (variables[i] != ' ') {
                opp += variables[i];
            }
            else secondSpace = true;
        }
        else if (firstSpace && secondSpace) {
            if (variables[i] != ' ') {
                str2 += variables[i];
            }
        }
    }

    return Output{ std::stof(str1), std::stof(str2), opp };
}

std::string Core::ToFloat()
{
    std::cin.imbue(std::locale(std::cin.getloc(), new ChangeDelimiter));

    std::string input;
    std::cin >> input;

    Output Variables = GetSegments(input);

    float output = Calculate(Variables.num1, Variables.num2, Variables.opperation);
    return std::to_string(output);
}


float Core::Calculate(float num1, float num2, std::string opperation)
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
    }
}
