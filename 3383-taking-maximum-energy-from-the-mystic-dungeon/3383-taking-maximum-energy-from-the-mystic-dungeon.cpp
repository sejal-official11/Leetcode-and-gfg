class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        // this code shows TLE becuse of n^2 TComplexity
        // int maxSum = INT_MIN;

        // for(int i = 0; i < energy.size(); i++) {
        //     int sum = 0;
        //     for(int j = i; j < energy.size(); j = j+k) {
        //         sum += energy[j];
        //        }
        //     maxSum = max(sum, maxSum);

        //     }
        // return maxSum;

        // here we will be using dynamic programming and we will traverse form
        // last to first index so that we dont have to traverse each every index
        // again and again
        vector<int> dp(n, 0);
        int maxSum = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {

            dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);
            maxSum = max(dp[i], maxSum);
        }
        return maxSum;
    }
};