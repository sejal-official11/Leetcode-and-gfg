class Solution {
private:
      int trib(int n, vector<int> &dp) {
        // Base Case
        if(n == 0) return dp[n] = 0;
        if(n == 1 || n == 2) return dp[n] = 1;

        if(dp[n] != -1) return dp[n];
        
        dp[n] = trib(n-1, dp) + trib(n-2, dp) + trib(n-3, dp);
        return dp[n];
      }    

public:
    int tribonacci(int n) {
       vector<int> dp(n+1, -1);
       return trib(n, dp);
    }
};