#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        map<int, int> countMax;
        for (int num : nums) {
            countMax[num]++;
        }
        int maxNum = -1;
        for (auto it = countMax.rbegin(); it != countMax.rend(); it++) {
            if (it->second == 1) {
                maxNum = max(it->first, maxNum);
            }
        }
        return maxNum;
    }
};
