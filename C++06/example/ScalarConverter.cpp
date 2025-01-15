#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>
#include <stdexcept>

class ScalarConverter {
private:
    // Private constructor and destructor to prevent instantiation
    ScalarConverter() {}
    ~ScalarConverter() {}
    
    static bool isChar(const std::string& input) {
        return input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]);
    }

    static bool isInt(const std::string& input) {
        try {
            std::stoi(input);
            return true;
        } catch (...) {
            return false;
        }
    }

    static bool isFloat(const std::string& input) {
        try {
            std::stof(input);
            return input.find('f') != std::string::npos;
        } catch (...) {
            return false;
        }
    }

    static bool isDouble(const std::string& input) {
        try {
            std::stod(input);
            return input.find('f') == std::string::npos;
        } catch (...) {
            return false;
        }
    }

    static void printChar(double value) {
        if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || std::isnan(value)) {
            std::cout << "char: impossible" << std::endl;
        } else if (!std::isprint(static_cast<char>(value))) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        }
    }

    static void printInt(double value) {
        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value)) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        }
    }

    static void printFloat(double value) {
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }

    static void printDouble(double value) {
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    }

public:
    static void convert(const std::string& input) {
        double value = 0.0;

        if (isChar(input)) {
            value = static_cast<double>(input[0]);
        } else if (isInt(input)) {
            value = std::stod(input);
        } else if (isFloat(input)) {
            value = std::stof(input);
        } else if (isDouble(input)) {
            value = std::stod(input);
        } else if (input == "-inff" || input == "+inff" || input == "nanf") {
            value = std::stof(input.substr(0, input.size() - 1)); // Remove 'f'
        } else if (input == "-inf" || input == "+inf" || input == "nan") {
            value = std::stod(input);
        } else {
            std::cerr << "Error: Invalid input" << std::endl;
            return;
        }

        // Output conversions
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    }
};

int main(int argc, char **argv) {
    if (argc != 2)
    {
        std::cout << "Please input a single argument" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);

    return 0;
}
