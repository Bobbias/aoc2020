#include "constants.hpp"
#include "util.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>

/*
 * note: find the two entries that sum to 2020 and then multiply those two
 * numbers together.
 *
 */

const auto &getInputVector() {

  std::ifstream ifs(INPUT_FOLDER + "day1.input.txt", std::ifstream::in);
  auto *v = new std::vector<util::line>;
  readLines(ifs, std::back_inserter((*v)));

  return (*v);
}

auto solveDay1Part1() {
  auto items{getInputVector()};

  for (const auto &l : items) {
    std::cout << l << "\n";
  }

  std::vector<int> ints;
  std::transform(items.begin(), items.end(), std::back_inserter(ints),
                 [](const std::string &s) { return std::stoi(s); });
  std::sort(ints.begin(), ints.end());

  std::cout << "as sorted ints:\n";

  for (const auto &n : ints) {
    std::cout << n << "\n";
  }

  const auto &out = filterReduce(
      ints.begin(), ints.end(),
      [ints](const auto &a) { return isDay1SolutionNumber(a, ints); },
      [](const auto &a) { return getSecondDay1SolutionNumber<int>(a); });

  if (out) {
    std::cout << "output:\n";

    std::cout << out.value() << "\n";
  } else {
    std::cout << "shit's broke yo\n";
  }
}

auto solveDay10Part1(){

};

int main() {

  solveDay1Part1();

  return 0;
}
