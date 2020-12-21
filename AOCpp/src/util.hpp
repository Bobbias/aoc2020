//
// Created by Bobbias on 2020-12-13.
//

#ifndef UNTITLED_UTIL_HPP
#define UNTITLED_UTIL_HPP

#include <functional>
#include <optional>
#include <string>

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
auto isDay1SolutionNumber(const t &a, ForwardIter ints) {
    if (std::find(ints.begin(), ints.end(), 2020 - a) != ints.end()) return true;
    else return false;
}

///
/// \tparam t
/// \param a
/// \return
template<Integral t>
std::optional<t> getSecondDay1SolutionNumber(const t &a) {
    return std::optional<t>(a * (2020 - a));
}

/// Iterates through the given iterator and applies pred to each input, when the predicate is true, it will apply
/// \tparam ForwardIter The type of our input iterator
/// \tparam UnaryPred The type of the predicate parameter function
/// \tparam BinaryFunction The Type of the reduce parameter function
/// \param begin
/// \param end
/// \param pred A predicate to apply to
/// \param fun The function to apply to the filtered result(s)
/// \return
template<typename ForwardIter, typename UnaryPred, typename BinaryFunction>
auto filterReduce(ForwardIter begin, ForwardIter end, UnaryPred pred, BinaryFunction fun) -> decltype(fun(*begin)) {
    while (begin != end) {
        if (pred(*begin)) {
            std::optional<int> result = fun(*begin);
            return result;
        }
        begin++;
    }
    return std::optional<int>(std::nullopt);
}

#endif // UNTITLED_UTIL_HPP
