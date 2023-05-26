//
// Created by Artemis on 25/05/2023.
//

#ifndef APT3_UTILS_H
#define APT3_UTILS_H

#include <fstream>
#include <algorithm>
#include <iostream>

enum ReturnType {
    SUCCESS,
    FAILURE,
    INVALID,
    EOFILE,
    HELP
};

inline bool validateFileExistence(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

// trim from start
inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

inline ReturnType getInt(int& value) {
    std::string input;
    std::cin >> input;

    ReturnType result = ReturnType::SUCCESS;

    if (input == "help") {
        result = ReturnType::HELP;
    } else {
        try {
            size_t pos;
            value = std::stoi(input, &pos);

            if (pos != input.length()) {
                result = ReturnType::INVALID;
            }
        } catch (const std::out_of_range&) {
            result = ReturnType::INVALID;
        } catch (const std::invalid_argument&) {
            result = ReturnType::INVALID;
        }
    }

    return result;
}

inline ReturnType getUnsigned(unsigned int& value) {
    std::string input;
    std::cin >> input;

    ReturnType result = ReturnType::SUCCESS;

    if (input == "help") {
        result = ReturnType::HELP;
    } else {
        try {
            size_t pos;
            value = std::stoul(input, &pos);

            if (pos != input.length()) {
                result = ReturnType::INVALID;
            }
        } catch (const std::out_of_range&) {
            result = ReturnType::INVALID;
        } catch (const std::invalid_argument&) {
            result = ReturnType::INVALID;
        }
    }

    return result;
}

inline ReturnType getDouble(double& value) {
    std::string input;
    std::cin >> input;

    ReturnType result = ReturnType::SUCCESS;

    if (input == "help") {
        result = ReturnType::HELP;
    } else {
        try {
            size_t pos;
            value = std::stod(input, &pos);

            if (pos != input.length()) {
                result = ReturnType::INVALID;
            }
        } catch (const std::out_of_range&) {
            result = ReturnType::INVALID;
        } catch (const std::invalid_argument&) {
            result = ReturnType::INVALID;
        }
    }

    return result;
}

inline ReturnType getLine(std::string& value) {
    std::getline(std::cin, value);

    ReturnType result = ReturnType::SUCCESS;

    if (value == "help") {
        result = ReturnType::HELP;
    } else if (std::cin.eof()) {
        result = ReturnType::EOFILE;
    }

    return result;
}

#endif //APT3_UTILS_H
