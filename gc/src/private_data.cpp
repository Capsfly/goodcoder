//
// Created by suichunyu on 2023/3/29.
//
#ifndef UNTITLED25_PRIVATE_DATA_CPP
#define UNTITLED25_PRIVATE_DATA_CPP

#include "../include/private_data.h"

namespace goodcoder {
void private_process::setPid(int pid) {
    _pid = pid;
}

void private_process::setProcessName(std::string process_name) {
    _process_name = process_name;
}

void private_process::setProcessStatus(Process_status ps) {
    _status = ps;
}

void person::setWeight(Weight w) {
    _w = w;
}

void person::setHeight(Height h) {
    _h = h;
}

int person::id() {
    return _id;
}

int person::setId(int id) {
    _id = id;
    return 0;
}
}  // namespace goodcoder

#endif