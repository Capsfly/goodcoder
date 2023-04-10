//
// Created by suichunyu on 2023/3/27.
//

#ifndef UNTITLED25_DICT_PARSE_H
#define UNTITLED25_DICT_PARSE_H

#include "dict_pattern_register.h"
#include "enum_data.h"
#include "private_data.h"
#include "private_parse.h"
#include "public_parse.h"

#include <fstream>
#include <type_traits>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace goodcoder {
const std::string COL_DELIMETER = "\\t";
class dict_parse {
public:
    int open(std::string s);
    int conf();  // 配置每一列的格式
    int read_next_line(const std::string delimiter = COL_DELIMETER);
    int read_specific_line(int target_line, const std::string delimiter = COL_DELIMETER);

    template <class T>
    int parse_to_val(int row, int col, T *val, int arr_size = 0) {
        read_specific_line(row);
        if (arr_size) {
            parse_array_val(_now_row_content[col], val, arr_size);
        } else {
            parse_single_val(_now_row_content[col], val);
        }
        return 0;
    }

    std::vector<std::string> now_row_content();

private:
    std::string _file_path;  // 想要读取的文件路径
    std::ifstream _in;
    int _now_row;                               // 现在读取到了第几行
    std::vector<std::string> _now_row_content;  // 当前行的内容
    std::unordered_map<int, std::shared_ptr<dict_col_meta_data>>
            _col_type;  // 第一维是列数，第二维度是当前列的格式
};
}  // namespace goodcoder

#endif  // UNTITLED25_DICT_PARSE_H
