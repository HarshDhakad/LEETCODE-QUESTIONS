#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, length = 0;
        map<int, int> mp;

        while (right < fruits.size()) {
            mp[fruits[right]]++;
            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            length = max(length, right - left + 1);
            right++;
        }
        return length;
    }
};

int main() {
    Solution solution;
    vector<int> fruits;
    int n, fruit;

    cout << "Enter the number of fruits: ";
    cin >> n;
    cout << "Enter the types of fruits: ";
    for (int i = 0; i < n; i++) {
        cin >> fruit;
        fruits.push_back(fruit);
    }

    int result = solution.totalFruit(fruits);
    cout << "The maximum number of fruits you can collect in two baskets is: " << result << endl;

    return 0;
}
