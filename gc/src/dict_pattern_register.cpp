//
// Created by suichunyu on 2023/3/28.
//

#include "../include/dict_pattern_register.h"

namespace goodcoder {
std::unordered_map<int, std::shared_ptr<dict_col_meta_data>> dict_pattern_register::_index_to_meta;

void dict_pattern_register::insert(int index, Dict_data_type type, std::string function) {
    _index_to_meta[index] = std::make_shared<dict_col_meta_data>(type, function);
}

std::unordered_map<int, std::shared_ptr<dict_col_meta_data>>
dict_pattern_register::index_to_meta() {
    return _index_to_meta;
}
}  // namespace goodcoder
