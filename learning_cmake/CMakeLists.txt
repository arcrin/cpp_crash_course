project(cmake_course)
cmake_minimum_required(VERSION 3.20)

set(sample_str
    test_key: test_value
)

message(${sample_str})

string(REPLACE ":" ";" target_data ${sample_str})
message(${target_data})

list(GET target_data 0 key)
list(GET target_data 1 value)

message(${key}_${value})