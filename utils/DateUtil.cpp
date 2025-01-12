//
// Created by student on 20.12.2024.
//
#include "DateUtil.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <string>

string DateUtil::getDate() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();
    return str;
}
