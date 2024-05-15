#include<iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScore(vector<int> cardPoints, int k) {
        int leftSum = 0, rightSum = 0, maxSum = 0;
        
        // Calculate the initial sum of the first 'k' cards from the left
        for(int i = 0; i < k; i++)
            leftSum += cardPoints[i];
        
        // Initialize maxSum with the initial sum
        maxSum = leftSum;
        
        // Start from the end of the array
        int rightIndex = cardPoints.size() - 1;
        
        // Move 'k' cards from the right to the left and update maxSum
        for(int i = k - 1; i >= 0; i--) {
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightIndex--];
            maxSum = max(maxSum, leftSum + rightSum);
        }
        
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << "Maximum score: " << sol.maxScore(cardPoints, k) <<endl;
    return 0;
}
