#include <iostream>
#include <cstdlib> // For strtod

int main() {
    const char* str = "123.450xyz";
    char* endPtr;

    // Convert the string to a double
    double num = strtod(str, &endPtr);

    std::cout << "Converted number: " << num << std::endl;  // Outputs: 123.456
    std::cout << "Unconverted part: " << endPtr << std::endl;  // Outputs: xyz

    return 0;
}
