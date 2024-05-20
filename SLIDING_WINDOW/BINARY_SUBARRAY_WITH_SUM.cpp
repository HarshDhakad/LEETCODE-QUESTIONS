#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int possibleNumber(vector<int>& nums, int k){
        int count = 0, left = 0, right = 0, sum = 0;
        while (right < nums.size()){
            sum += nums[right] % 2;
            while (sum > k && left <= right){
                sum -= nums[left] % 2;
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int k) {
        return possibleNumber(nums, k) - possibleNumber(nums, k - 1);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 1, 1}; 
    int k = 3; 

    int result = solution.numSubarraysWithSum(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}