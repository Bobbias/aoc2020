#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "constants.h"
#include "util.h"

/*
 * note: find the two entries that sum to 2020 and then multiply those two numbers together.
 *
 */

auto getInputVector() {

    std::ifstream ifs(INPUT_FOLDER + "day1.input.txt", std::ifstream::in);
    std::vector<util::Line> v;
    read_lines(ifs, std::back_inserter(v));

    return v;
}

int main() {

    auto items{getInputVector()};

    for (const auto &l : items) {
        std::cout << l << "\n";
    }

    std::vector<int> ints;
    std::transform(items.begin(),
                   items.end(),
                   std::back_inserter(ints),
                   [](const std::string &s) { return std::stoi(s); });
    std::sort(ints.begin(), ints.end());

    std::cout << "as sorted ints:\n";

    for (const auto &n : ints) {
        std::cout << n << "\n";
    }
    std::vector<int> out;


    std::cout << "output:\n";

    auto res = std::reduce(ints.begin(), ints.end(),
                           0,
                           [ints](const auto &a, const auto &b) {
                               auto c = std::find(ints.begin(), ints.end(), 2020 - a);
                               if (c != ints.end()) {
                                   return *c * a;
                               } else {
                                   return 0;
                               }
                           }
    );

    std::cout << res << "\n";

    return 0;
}
