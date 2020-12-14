//
// Created by Bobbias on 2020-12-13.
//

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include <string>

namespace util {
    class Line : public std::string {
        friend std::istream &operator>>(std::istream &is, Line &line) {
            return std::getline(is, line);
        }
    };
}

template<class OutIt>
void read_lines(std::istream &is, OutIt dest) {
    typedef std::istream_iterator<util::Line> InIt;
    std::copy(InIt(is), InIt(), dest);
}

#endif //UNTITLED_UTIL_H
