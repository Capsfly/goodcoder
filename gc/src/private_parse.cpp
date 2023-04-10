//
// Created by suichunyu on 2023/3/27.
//

#ifndef UNTITLED25_PRIVATE_PARSE_CPP
#define UNTITLED25_PRIVATE_PARSE_CPP
#include "../include/private_data.h"
#include "../include/private_parse.h"

#include <sstream>

namespace goodcoder {
int parse_single_val(const std::string &s, private_process *p) {
    std::stringstream ss(s);
    int pid;
    std::string process_name;
    std::string flag;

    ss >> pid;
    ss >> process_name;
    ss >> flag;

    if (flag == "CREATE") {
        p->setProcessStatus(Process_status::CREATE);
    } else if (flag == "READY") {
        p->setProcessStatus(Process_status::READY);
    } else if (flag == "RUNNING") {
        p->setProcessStatus(Process_status::RUNNING);
    } else if (flag == "BLOCKING") {
        p->setProcessStatus(Process_status::BLOCKING);
    } else if (flag == "TERMINATING") {
        p->setProcessStatus(Process_status::TERMINATING);
    } else {
        return -1;
    }
    p->setPid(pid);
    p->setProcessName(process_name);

    return 0;
}

int parse_single_val(const std::string &s, person *p) {
    std::stringstream ss(s);
    std::string flag1;
    ss >> flag1;
    if (flag1 == "HIGH") {
        p->setHeight(Height::HIGH);
    } else if (flag1 == "MEDIUM") {
        p->setHeight(Height::MEDIUM);
    } else if (flag1 == "SHORT") {
        p->setHeight(Height::SHORT);
    }

    std::string flag2;
    ss >> flag2;
    if (flag2 == "FAT") {
        p->setWeight(Weight::FAT);
    } else if (flag2 == "MEDIUM") {
        p->setWeight(Weight::MEDIUM);
    } else if (flag2 == "SLIM") {
        p->setWeight(Weight::SLIM);
    }

    int toSetID;
    ss >> toSetID;
    p->setId(toSetID);

    return 0;
}

int parse_array_val(const std::string &s, private_process *p, int arr_size) {
    int pre_pos = 0;
    for (int i = 0; i < arr_size; i++) {
        int space_pos = s.find("\\m", pre_pos);
        char test_c = s[space_pos];
        std::string temp_str = s.substr(pre_pos, (space_pos - 1) - pre_pos + 1);
        parse_single_val(temp_str, &p[i]);
        pre_pos = space_pos + 3;
    }
    return 0;
}

int parse_array_val(const std::string &s, person *p, int arr_size) {
    int pre_pos = 0;
    for (int i = 0; i < arr_size; i++) {
        int deli_pos = s.find("\\m", pre_pos);
        std::string temp_str = s.substr(pre_pos, (deli_pos - 1) - pre_pos + 1);
        parse_single_val(temp_str, &p[i]);
        pre_pos = deli_pos + 3;
    }
    return 0;
}

}  // namespace goodcoder

#endif  // UNTITLED25_PRIVATE_PARSE_CPP
