/**
 * 17.18 Shortest Supersequence:
 *
 * You are given two arrays, one shorter (with all distinct elements) and one
 * longer. Find the shortest subarray in the longer array that contains all the elements in the shorter
 * array. The items can appear in any order.
 *
 * EXAMPLE
 * Input: {1, 5, 9} | {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7}
 *                                          ^^^^^^^^^^
 * Output: [7, 10] (the underlined portion above)
 */

#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

std::pair<int, int> shortest_supersequence(std::vector<int> &shorter, std::vector<int> &longer) {
    int lo = 0, hi = 0, unique_count = 0;
    std::unordered_map<int, int> counts;
    std::pair<int, int> best{0, std::numeric_limits<int>::max()};

    for (int i : shorter) {
        counts[i] = 0;
    }

    while (hi < longer.size()) {
        while (hi < longer.size() && unique_count < counts.size()) {
            if (counts.find(longer[hi]) != counts.end()) {
                if (++counts[longer[hi]] == 1) {
                    unique_count++;
                }
            }

            hi++;
        }

        while (lo < hi && unique_count == counts.size()) {
            if (hi - 1 - lo < best.second - best.first) {
                best = std::make_pair(lo, hi - 1);
            }

            if (counts.find(longer[lo]) != counts.end()) {
                if (--counts[longer[lo]] == 0) {
                    unique_count--;
                }
            }

            lo++;
        }
    }
    
    return best;
}

int main() {
    std::vector<int> shorter {1, 5, 9};
    std::vector<int> longer {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7};
    std::pair<int, int> result = shortest_supersequence(shorter, longer);
    std::cout << result.first << ' ' << result.second << std::endl;

    return 0;
}
