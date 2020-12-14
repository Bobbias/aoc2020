//
// Created by Bobbias on 2020-12-13.
//

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

#include <string>
#include <functional>
#include <optional>

namespace util {
    class line : public std::string {
        friend std::istream &operator>>(std::istream &is, line &line) {
            return std::getline(is, line);
        }
    };
}

template<class OutIt>
void readLines(std::istream &is, OutIt dest) {
    typedef std::istream_iterator<util::line> inIt;
    std::copy(inIt(is), inIt(), dest);
}

/*
 * idea:
 *  iterate each number
 *  subtract number from 2020 and run std::find to check if the result is in the list
 *  if it is, we're done, return current item, result, and current item * result
 *
 *  return {item, result, item * result};
 */

template<typename ForwardIter, typename UnaryPred, typename function>
auto filterReduce(ForwardIter begin, ForwardIter end, UnaryPred pred, function fun) -> decltype(fun(begin)) {
    while (begin != end) {
        if (pred(begin)) {
            return std::optional<decltype(fun(begin))>(fun(begin));
        }
        begin++;
    }
    return {};
}

#endif //UNTITLED_UTIL_H
