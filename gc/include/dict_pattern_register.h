//
// Created by suichunyu on 2023/3/28.
//

#ifndef UNTITLED25_DICT_PATTERN_REGISTER_H
#define UNTITLED25_DICT_PATTERN_REGISTER_H

#include "enum_data.h"

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

namespace goodcoder {
class dict_col_meta_data {
public:
    dict_col_meta_data(Dict_data_type type, std::string function) :
            _type(type), _function(function) {}

private:
    Dict_data_type _type;
    std::string _function;//
};

class dict_pattern_register {
public:
    static void insert(int index, Dict_data_type type, std::string function);
    static std::unordered_map<int, std::shared_ptr<dict_col_meta_data>> index_to_meta();

private:
    static std::unordered_map<int, std::shared_ptr<dict_col_meta_data>> _index_to_meta;
};
}  // namespace goodcoder

#endif  // UNTITLED25_DICT_PATTERN_REGISTER_H
