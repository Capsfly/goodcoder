//
// Created by suichunyu on 2023/3/27.
//

#ifndef UNTITLED25_PUBLIC_PARSE_CPP
#define UNTITLED25_PUBLIC_PARSE_CPP
#include "../include/public_parse.h"
#include <string>
#include <sstream>

namespace goodcoder {
int parse_single_val(const std::string &s, int *val) {
    *val = std::stoi(s);
    return 0;
}

int parse_single_val(const std::string &s, float *val) {
    *val = std::stof(s);
    return 0;
}

int parse_array_val(const std::string &s, char *val, int char_arr_size) {
    int pos = 0;
    for (auto &i : s) {
        val[pos++] = i;
    }
    return 0;
}

int parse_array_val(const std::string &s, int *val, int int_arr_size) {
    std::stringstream ss(s);
    for (int i = 0; i < int_arr_size; i++) {
        ss >> val[i];
    }
    return 0;
}

int parse_array_val(const std::string &s, float *val, int float_arr_size) {
    std::stringstream ss(s);
    for (int i = 0; i < float_arr_size; i++) {
        ss >> val[i];
    }
    return 0;
}
}  // namespace goodcoder

#endif  // UNTITLED25_PUBLIC_PARSE_CPP
