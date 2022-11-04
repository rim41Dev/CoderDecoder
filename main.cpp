#include <iostream>
#include <unistd.h>
#include "CodeDecode.hpp"

int getmode(int mode)
{
    std::cout << "Write 1 for code, write 2 for decode, write -1 for exit:" << std::endl;
    std::cin >> mode;
    std::cin.ignore(); // необходимо для корректной работы getline
    return mode;
}

int main()
{
    int mode = 0;

    while (true) {
        std::string str;

        mode = getmode(mode);
        if (mode == 0) {
            std::cin.clear();
            while(std::cin.get() != '\n');
            std::cout << "Wrong mode (string not int), try again" << std::endl;
            continue;
        }
        else if (mode == -1) {
            std::cout << "Bye user!";
            break;
        }
        else if (mode == 1) {
            std::cout << "Text for code:" << std::endl;
            getline(std::cin, str);
            std::cout << "Coded text: " << std::endl << Code(str) << std::endl;
        }
        else if (mode == 2) {
            std::cout << "Text for decode:" << std::endl;
            getline(std::cin, str);
            std::cout << "Decoded text:" << std::endl << DeCode(str) << std::endl;
        }
        else {
            std::cout << "Wrong mode (bad int), try again" << std::endl;
            continue;
        }
    }
    sleep(3);
    return 0;
}