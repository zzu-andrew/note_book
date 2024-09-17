#include <cctype>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <utility>  // for std::forward()
#include <memory>
#include <functional>
#include <algorithm>
#include <sstream>
#include <atomic>
#include <iostream>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <condition_variable>
#include <algorithm>
#include <unordered_map>


using namespace std;




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int left = 0, maxLength = 0;
        for (int right = 0; right < s.length(); ++right) {
            if (charIndex.find(s[right]) != charIndex.end() && charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

class Solution1 {
public:
    static int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int left = 0, maxLength = 0;
        for (int right = 0; right < s.length(); ++right) {
            //  charIndex[s[right]] >= left 因为map中没有剔除前面重复的字符 这里保证一下，只有重复的是left后面的才更新left
            if (charIndex.find(s[right]) != charIndex.end() && charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};






int main() {



    cout << Solution1::lengthOfLongestSubstring("abba") << std::endl;












    return 0;
}