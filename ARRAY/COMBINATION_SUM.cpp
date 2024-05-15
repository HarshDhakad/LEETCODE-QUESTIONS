#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> current;
    vector<vector<int>> result;

public:
    void DFS(vector<int>& candidates, int index, int target) {
        if (target == 0) {
            result.push_back(current);
        } else if (target > 0) {
            for (int j = index; j < candidates.size(); j++) {
                if (target < candidates[j]) break;  // Early termination
                current.push_back(candidates[j]);
                DFS(candidates, j, target - candidates[j]);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort candidates
        DFS(candidates, 0, target);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = solution.combinationSum(candidates, target);

    // Print the results
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
