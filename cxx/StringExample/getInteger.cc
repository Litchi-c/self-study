// @Author : Sugar
// @Created Time : 2022-04-15 09:03:13
// @Description :
#include <iostream>
#include <string>
#include <sstream>

int getInteger(std::string prompt){
    int value;
    std::string line;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        std::istringstream stream(line);
        stream >> value >> std::ws;
        if (!stream.fail() && stream.eof())
            break;
        std::cout << "Illegal format: Try again. " << std::endl;
    }
    return value;
}

int getInteger(){
    return getInteger("");
}
