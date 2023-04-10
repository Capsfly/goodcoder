//
// Created by suichunyu on 2023/3/29.
//

#ifndef UNTITLED25_PUBLIC_PARSE_H
#define UNTITLED25_PUBLIC_PARSE_H

#include <string>

namespace goodcoder {
int parse_single_val(const std::string &s, int *val);

int parse_single_val(const std::string &s, float *val);

int parse_array_val(const std::string &s, char *val, int char_arr_size);

int parse_array_val(const std::string &s, int *val, int int_arr_size);

int parse_array_val(const std::string &s, float *val, int float_arr_size);
}  // namespace goodcoder

#endif  // UNTITLED25_PUBLIC_PARSE_H
