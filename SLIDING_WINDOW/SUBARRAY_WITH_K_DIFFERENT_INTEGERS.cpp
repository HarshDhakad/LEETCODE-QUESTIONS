#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findSubarray(vector<int> nums, int k) {
        int left = 0, right = 0, count = 0;
        map<int, int> mp;

        while (right < nums.size()) {
            mp[nums[right]]++;
            while (mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            count += right - left + 1;
            right++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findSubarray(nums, k) - findSubarray(nums, k - 1);
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int n, k, num;

    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter the number of distinct integers (k): ";
    cin >> k;

    int result = solution.subarraysWithKDistinct(nums, k);
    cout << "The number of subarrays with exactly " << k << " distinct integers is: " << result << endl;

    return 0;
}
