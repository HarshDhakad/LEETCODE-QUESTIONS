#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // To handle the case when a subarray sum equals `k` starting from index 0
        int sum = 0;
        int count = 0;

        for (int num : nums) {
            sum += num;
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            prefixSumCount[sum]++;
        }

        return count;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 1, 1}; // Example input
    int k = 2; // Example k value
    int result = solution.subarraySum(nums, k);
    std::cout << "Number of subarrays that sum to " << k << ": " << result << std::endl;
    return 0;
}
