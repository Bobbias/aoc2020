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

template<typename T>
concept Integral = std::is_integral<T>::value;

template<Integral t, typename ForwardIter>
auto p(const t &a, ForwardIter ints) {
    if (std::find(ints.begin(), ints.end(), a - 2020) != ints.end()) return true;
    else return false;
}

template<Integral t>
std::optional<t> f(const t &a) {
    return std::optional<t>(a * (2020 - a));
}

template<typename ForwardIter, typename UnaryPred, typename BinaryFunction>
auto filterReduce(ForwardIter begin, ForwardIter end, UnaryPred pred, BinaryFunction fun) {
    while (begin != end) {
        if (pred(*begin)) {
            std::optional<int> result = fun(*begin);
            return result;
        }
        begin++;
    }
    return std::optional<int>(std::nullopt);
}

#endif //UNTITLED_UTIL_H
