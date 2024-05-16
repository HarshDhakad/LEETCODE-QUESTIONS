#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0, zero = 0, left = 0, right = 0, size = nums.size();
        
        while (right < size) {
            if (nums[right] == 0) zero++;
            while (zero > k) {
                if (nums[left] == 0) zero--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        
        return maxLength;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int n, k, num;

    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter the number of allowed 0 to 1 flips (k): ";
    cin >> k;

    int result = solution.longestOnes(nums, k);
    cout << "The longest subarray with at most " << k << " zero(s) flipped to one(s) is: " << result << endl;

    return 0;
}
