//
// Created by wbai on 7/19/2023.
//

#ifndef CPP_CRASH_COURSE_CREATEANDDESTROY_H
#define CPP_CRASH_COURSE_CREATEANDDESTROY_H
#pragma once
#include <string>
#include <string_view>

class CreateAndDestroy {
public:
    CreateAndDestroy(int ID, std::string_view message); // constructor
    ~CreateAndDestroy(); // destructor

private:
    int m_ID; // ID number for object
    std::string m_message; //
};


#endif //CPP_CRASH_COURSE_CREATEANDDESTROY_H
