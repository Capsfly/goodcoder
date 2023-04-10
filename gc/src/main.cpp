#include "../include/dict_pattern_register.h"
#include "../include/enum_data.h"
#include "../include/public_parse.h"
#include "../include/dict_parse.h"
#include "../include/private_data.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <gtest/gtest.h>
#include <vector>
TEST(dict_parse, test_int) {
    std::vector<int> v{205, 29999, -1000, 0};
    goodcoder::dict_parse d;
    d.open("in.txt");

    for (int i = 0; i < v.size(); i++) {
        int temp_val;
        d.parse_to_val(i, 0, &temp_val);
        EXPECT_EQ(temp_val, v[i]);
    }
}

TEST(dict_parse, test_float) {
    std::vector<float> v{422.39, -103.8, -999, -0.005};
    goodcoder::dict_parse d;
    d.open("in.txt");

    for (int i = 0; i < v.size(); i++) {
        float temp_val;
        d.parse_to_val(i, 1, &temp_val);
        EXPECT_EQ(temp_val, v[i]);
    }
}

TEST(dict_parse, test_private_process) {
    std::vector<std::string> v{
            "2 scy RUNNING", "17777 ece RUNNING", "666 duke RUNNING", "17777 YSQ READY"};
    goodcoder::dict_parse d;
    d.open("in.txt");

    for (int i = 0; i < v.size(); i++) {
        goodcoder::private_process temp_process;
        d.parse_to_val(i, 2, &temp_process);

        std::stringstream ss;
        std::streambuf* buffer = std::cout.rdbuf();
        std::cout.rdbuf(ss.rdbuf());
        std::cout << temp_process;
        std::string temp_str;
        std::string val;
        while (ss >> temp_str) {
            val += temp_str;
            val += " ";
        }
        val.pop_back();
        EXPECT_EQ(val, v[i]);
        std::cout.rdbuf(buffer);
    }
}

TEST(dict_parse, test_int_array) {
    std::vector<std::vector<int>> v{{2, 3}, {0, -5}, {9, 6}, {-5, -1222}};
    goodcoder::dict_parse d;
    d.open("in.txt");

    for (int i = 0; i < v.size(); i++) {
        int* temp_int_arr = new int[v[i].size()];
        d.parse_to_val(i, 3, temp_int_arr, 2);

        for (int j = 0; j < v[i].size(); j++) {
            EXPECT_EQ(temp_int_arr[j], v[i][j]);
        }
        delete[] temp_int_arr;
    }
}

TEST(dict_parse, test_float_array) {
    std::vector<std::vector<float>> v{
            {2.722, 3.14}, {-3.14, 9.99}, {13333.3333, -13333.3333}, {996.000, 123}};
    goodcoder::dict_parse d;
    d.open("in.txt");

    for (int i = 0; i < v.size(); i++) {
        float* temp_float_arr = new float[v[i].size()];
        d.parse_to_val(i, 4, temp_float_arr, 2);

        for (int j = 0; j < v[i].size(); j++) {
            EXPECT_EQ(temp_float_arr[j], v[i][j]);
        }
    }
}

int main(int argc, char** argv) {
    // 注册格式
    goodcoder::dict_pattern_register::insert(0, goodcoder::Dict_data_type::INT, "INT");
    goodcoder::dict_pattern_register::insert(1, goodcoder::Dict_data_type::FLOAT, "FLOAT");
    goodcoder::dict_pattern_register::insert(2, goodcoder::Dict_data_type::PROCESS, "PROCESS");
    goodcoder::dict_pattern_register::insert(3, goodcoder::Dict_data_type::INT_ARRAY, "INT_ARRAY");
    goodcoder::dict_pattern_register::insert(
            4, goodcoder::Dict_data_type::FLOAT_ARRAY, "FLOAT_ARRAY");
    //类型要放到文件
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
