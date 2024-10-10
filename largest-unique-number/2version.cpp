#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> countMax;
        for (int num : nums) {
            countMax[num]++;
        }
        const int max = *max_element(nums.begin(), nums.end(), [nums, countMax](int a, int b)
        {
            return (abs(a) < abs(b) && countMax.at(b) == 1) || countMax.at(a) != 1;
        });
        if (countMax.at(max) != 1) {
            return -1;
        }
        return max;
    }
};
