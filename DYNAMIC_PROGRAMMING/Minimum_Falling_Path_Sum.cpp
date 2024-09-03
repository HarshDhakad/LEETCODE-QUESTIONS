#include<bits/stdc++.h>
/*************************************************************** C++ ***************************************************************/


//Approach-1 (Recur + Memoization) : O(m*n) (New test Case has been added, this will give TLE in last Test Case) (49 / 50 testcases passed)
//T.C : O(m*n)
//S.C : O(m*n) ~ O(1) (Excluding stack recursion space)

class Solution {
public:
    // MEMOIZATION 

    int solve(int n, vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo) {
        // Base Case: If it's the last row, return the current cell value
        if (row == n - 1) return matrix[row][col];

        // If the result is already computed, return it
        if (memo[row][col] != -1) return memo[row][col];

        // Initialize min_sum with a large value
        int min_sum = INT_MAX;

        // Go through the three possible directions: down, diagonally left, and diagonally right
        min_sum = min(min_sum, solve(n, matrix, row + 1, col, memo));
        if (col + 1 < n) 
            min_sum = min(min_sum, solve(n, matrix, row + 1, col + 1, memo));
        if (col - 1 >= 0)
            min_sum = min(min_sum, solve(n, matrix, row + 1, col - 1, memo));

        // Add the current cell's value to the minimum sum and store it in memo
        memo[row][col] = matrix[row][col] + min_sum;

        return memo[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int min_sum = INT_MAX;
        int n = matrix.size();

        // Memoization table of size n x n
        vector<vector<int>> memo(n, vector<int>(n, -1));

        // Initially go through all columns of the first row
        for (int col = 0; col < n; col++) {
            min_sum = min(min_sum, solve(n, matrix, 0, col, memo));
        }

        return min_sum;
    }
};


//Approach-2 (Bottom UP DP) : O(m*n)
//T.C : O(m*n)
//S.C :  O(m*n)


class Solution {
public:  
    // TABULAR METHOD

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // make a dp of size matrix and fill with MAX value
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));

        // First row is filled in dp 
        for(int col=0;col<n;col++)   dp[0][col]=matrix[0][col];

        // from 1st row all rows filled according to minimum value that comes from 3 paths and from its above row 
        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                int min_sum=INT_MAX;
                // take minimum from its above 3 paths
                min_sum=min(min_sum,dp[row-1][col]);
                if(col-1 >=0 ) min_sum=min(min_sum,dp[row-1][col-1]);
                if(col+1 < n)  min_sum=min(min_sum,dp[row-1][col+1]);

                //filled dp with minimum
                dp[row][col]=matrix[row][col] + min_sum;
            }
        }

        //find minimum in last row
        int result=INT_MAX;
        for(int col=0;col<n;col++){
            result=min(result,dp[n-1][col]);
        }
        return result;
    }
};


//Approach-3 (Bottom Up Space Optimized)
//T.C : O(m*n)
//S.C :  O(m*n)

// in this we donot make full size dp but only we make a prev(1D vector) to store its pev row optimised answer 
//it decreases space complexity 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> prev(n);
        for(int col = 0; col<n; col++)
            prev[col] = A[0][col];
        
        for(int row = 1; row<n; row++) {
            vector<int> curr(n);
            for(int col = 0; col<n; col++) {
                curr[col] = A[row][col] + min({prev[max(0, col-1)],  prev[col],  prev[min(n-1, col+1)]});
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};

