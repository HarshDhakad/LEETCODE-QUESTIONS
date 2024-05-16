#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, size = s.size();
        int left = 0, right = 0;
        int hash[256];
        
        // Fill the hash array with -1
        fill(begin(hash), end(hash), -1);

        while (right < size) {
            if (hash[s[right]] != -1) {
                if (hash[s[right]] >= left) {
                    left = hash[s[right]] + 1;
                }
            }
            maxLength = max(maxLength, right - left + 1);
            hash[s[right]] = right;
            right++;
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = solution.lengthOfLongestSubstring(s);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;
    return 0;
}
