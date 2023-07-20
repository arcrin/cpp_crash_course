//
// Created by wbai on 7/19/2023.
//

#ifndef CPP_CRASH_COURSE_BADTIMECLASS_H
#define CPP_CRASH_COURSE_BADTIMECLASS_H
#pragma once

class BadTimeClass {
public:
    void setTime(int hour, int minute, int second);

    [[nodiscard]] int getHour() const;

    int& badSetHour(int hour);
private:
    int m_hour{0};
    int m_minute{0};
    int m_second{0};
};


#endif //CPP_CRASH_COURSE_BADTIMECLASS_H
