#include <string>
#include "GetRand.hpp"
std::string Code(std::string str)
{
    int factor = GetRandomNumber(1,5);
    int step = GetRandomNumber(10,20);
    std::string result;
    for (char c : str) {
        char x = c + (step * factor);
        result.push_back(x);
    }
    std::string stepCode = std::to_string(step);
    result.push_back(stepCode[0]);
    result.push_back(factor);
    result = stepCode[1] + result;

    return result;
}

std::string DeCode(std::string str)
{
    int step;
    std::string result;
    std::string strStep;
    char factor = str[str.size() - 1];
    strStep = std::string () + str[str.size() - 2] + str[0];
    step = stoi(strStep);
    str.pop_back();
    str.pop_back();
    str.erase(0, 1);
    for (char c : str) {
        char x = c - (step * factor);
        result.push_back(x);
    }
    return result;
}