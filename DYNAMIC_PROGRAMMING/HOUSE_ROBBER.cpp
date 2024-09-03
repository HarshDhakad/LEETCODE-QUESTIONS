#include<bits/stdc++.h>
/*************************************************************** C++ ***************************************************************/

//Approach-1 (Recur + Memoization) : O(m*n) (ALL testcases passed)
//T.C : O(m*n)
//S.C : O(101) ~ O(1) (Excluding stack recursion space)

class Solution {
    private:
    int memo[101];
public:
    // MEMOIZATION
    int choose(int n,vector<int> &nums,int index){
        // Base Case:
        if(index>=n) return 0;
        //If memo already filled
        if(memo[index]!=-1)  return memo[index];

        //You have two chance that steal house or not 
        int steal=nums[index] + choose(n,nums,index+2);
        int notSteal=choose(n,nums,index+1);

        return memo[index]=max(steal,notSteal);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        fill(begin(memo), end(memo), -1);
        return choose(n,nums,0);
    }
};

//Approach-2 (Bottom UP DP) : O(m*n)
//T.C : O(n)
//S.C :  O(n+1)


class Solution {
public:

//TABULAR APPROACH

    int rob(vector<int>& nums) {
        int n=nums.size();
        // here in dp , index i shows the optimal answer till that number of house 
        // like index=0 => no house ,index=1 => till 0th index  
        vector<int> dp(n+1,-1);

        // dp[0]=> no house stolen, dp[1]=> 1 house stolen means 0th index in nums
        dp[0]=0,dp[1]=nums[0];

        for(int i=2;i<n+1;i++){
            dp[i]=max(nums[i-1] + dp[i-2] , dp[i-1]);
        }
        return dp[n];
    }
};