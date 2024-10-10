#include <utility>
class Solution {
public:
    int calculate(int low, int high) {
        if (low >= high)
        {
            return 0;
        }
        if (low + 1 == high) {
            return 0;
        }
        int newLimit = high / 2;
        if (newLimit < low)
            newLimit = low;
        if (newLimit == low)
            newLimit += 1;
        int res = std::max(calculate(low, newLimit), calculate(newLimit, high));
        return newLimit + res;
    }
    int getMoneyAmount(int n) {
        int higher = n * 0.7;
        if (higher + 2 == n) {
            higher = higher - 1;
        }
        return higher + calculate(higher + 1, n); 
    }
};
