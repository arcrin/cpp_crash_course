//
// Created by wbai on 8/1/2023.
//

#ifndef CPP_CRASH_COURSE_BASE2_H
#define CPP_CRASH_COURSE_BASE2_H


class Base2 {
public:
    explicit Base2(char letter) : m_letter{letter} {}
    char getData() const { return m_letter; }
private:
    char m_letter;
};


#endif //CPP_CRASH_COURSE_BASE2_H
