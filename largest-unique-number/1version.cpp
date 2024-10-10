#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        const int max = *max_element(nums.begin(), nums.end(), [nums](int a, int b)
        {
            return (abs(a) < abs(b) && count(nums.begin(), nums.end(), b) == 1) || count(nums.begin(), nums.end(), a) != 1;
        });
        if (count(nums.begin(), nums.end(), max) != 1) {
            return -1;
        }
        return max;
    }
};
