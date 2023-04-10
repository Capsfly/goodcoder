//
// Created by suichunyu on 2023/3/27.
//

#include "../include/dict_parse.h"
#include "../include/private_data.h"
#include "../include/private_parse.h"
#include "../include/public_parse.h"

#include <iostream>

namespace goodcoder {
int dict_parse::read_next_line(const std::string delimiter) {
    std::string temp_str;
    std::getline(_in, temp_str);

    size_t find_pos = temp_str.find(delimiter);
    size_t bef_pos = 0;
    _now_row_content.clear();
    while (find_pos != temp_str.npos) {
        std::string sub_str = temp_str.substr(bef_pos, (find_pos - 1) - bef_pos + 1);
        _now_row_content.push_back(sub_str);
        bef_pos = find_pos + 3;
        find_pos = temp_str.find(delimiter, bef_pos);
    }
    std::string sub_str = temp_str.substr(bef_pos);
    _now_row_content.push_back(sub_str);

    _now_row++;
    return 0;
}

int dict_parse::conf() {
    // 遍历dict_register
    for (auto& iter : dict_pattern_register::index_to_meta()) {
        int now_col = iter.first;
        std::shared_ptr<dict_col_meta_data> now_dict_col_meta_data = iter.second;
        _col_type[now_col] = now_dict_col_meta_data;
    }
    return 0;
}

int dict_parse::read_specific_line(int target_line, const std::string delimiter) {
    if (target_line == _now_row) {
        return 0;
    } else if (target_line > _now_row) {
        read_next_line(delimiter);
    } else {
        _in.open(_file_path);
        for (int i = 0; i < target_line; i++) {
            read_next_line(delimiter);
        }
    }
    return 0;
}

std::vector<std::string> dict_parse::now_row_content() {
    return _now_row_content;
}

int dict_parse::open(std::string s) {
    _in.open(s);
    _file_path = s;
    _now_row = -1;
    _now_row_content.clear();
    conf();
    return 0;
}
}  // namespace goodcoder
