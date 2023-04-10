//
// Created by suichunyu on 2023/3/27.
//

#ifndef UNTITLED25_PRIVATE_DATA_H
#define UNTITLED25_PRIVATE_DATA_H
#include "enum_data.h"

#include <iostream>
#include <string>

namespace goodcoder {
class private_process {
    int _pid;
    std::string _process_name;
    Process_status _status;

public:
    private_process(int _pid, std::string _process_name, Process_status _status) :
            _pid(_pid), _process_name(_process_name), _status(_status) {}
    private_process() {}
    ~private_process() {}
    void setPid(int pid);
    void setProcessName(std::string process_name);
    void setProcessStatus(Process_status ps);
    friend std::ostream &operator<<(std::ostream &os, private_process &p) {
        os << p._pid << " ";
        os << p._process_name << " ";

        if (p._status == Process_status::TERMINATING) {
            os << "TERMINATING";
        } else if (p._status == Process_status::BLOCKING) {
            os << "BLOCKING";
        } else if (p._status == Process_status::RUNNING) {
            os << "RUNNING";
        } else if (p._status == Process_status::READY) {
            os << "READY";
        } else if (p._status == Process_status::CREATE) {
            os << "CREATE";
        }
        os << " ";

        return os;
    }
};

class person {
    Weight _w;
    Height _h;
    int _id;

public:
    person(int id, Weight w, Height h) : _id(id), _w(w), _h(h) {}
    person() {}
    void setWeight(Weight w);
    void setHeight(Height h);
    int setId(int id);
    int id();
    friend std::ostream &operator<<(std::ostream &os, person &p) {
        os << "Weight==";
        if (p._w == Weight::SLIM) {
            os << "SLIM";
        } else if (p._w == Weight::MEDIUM) {
            os << "MEDIUM";
        } else {
            os << "FAT";
        }
        os << " ";

        os << "Height==";
        if (p._h == Height::SHORT) {
            os << "SHORT";
        } else if (p._h == Height::MEDIUM) {
            os << "MEDIUM";
        } else {
            os << "HIGH";
        }
        os << " ";

        os << "id==" << p._id << std::endl;
        return os;
    }
};
}  // namespace goodcoder

#endif  // UNTITLED25_PRIVATE_DATA_H
