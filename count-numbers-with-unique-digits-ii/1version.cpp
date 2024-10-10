#include <string>
#include <set>
#include<iostream>
using namespace std;
class Solution {
public:
    int numberCount(int a, int b) {
      int count = 0;
        for (int i = a; i <= b; i++) {
            string number = to_string(i);
            set<char> uniqueness(number.begin(), number.end());
            if (number.size() == uniqueness.size())
              ++count;
        }
      return count;
    }
};
