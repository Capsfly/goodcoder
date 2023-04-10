//
// Created by suichunyu on 2023/3/29.
//

#ifndef UNTITLED25_PRIVATE_PARSE_H
#define UNTITLED25_PRIVATE_PARSE_H

#include "private_data.h"

#include <sstream>
namespace goodcoder {
int parse_single_val(const std::string &s, private_process *p);//封装成类

int parse_array_val(const std::string &s, private_process *p, int arr_size);

int parse_single_val(const std::string &s, person *p);

}  // namespace goodcoder

#endif  // UNTITLED25_PRIVATE_PARSE_H
