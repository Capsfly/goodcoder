//
// Created by suichunyu on 2023/3/28.
//

#ifndef UNTITLED25_ENUM_DATA_H
#define UNTITLED25_ENUM_DATA_H

namespace goodcoder {
enum class Process_status { CREATE, READY, RUNNING, BLOCKING, TERMINATING };

enum class Height { HIGH, MEDIUM, SHORT };

enum class Weight { FAT, MEDIUM, SLIM };

enum class Dict_data_type {
    INT,
    FLOAT,
    PROCESS,
    PERSON,
    CHAR_ARRAY,
    INT_ARRAY,
    FLOAT_ARRAY,
    PROCESS_ARRAY,
    PERSON_ARRAY
};
}  // namespace goodcoder

#endif  // UNTITLED25_ENUM_DATA_H
