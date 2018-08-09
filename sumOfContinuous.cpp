class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size(), 0);
        dp[0] = array[0];
        int mMax = dp[0];
        for(int i=1; i<array.size(); ++i) {
            dp[i] = max(dp[i-1]+array[i], array[i]);//这里为什么不是dp[i] = max(dp[i-1]+array[i], dp[i-1])
                                                    //dp[i-1]不是以array[i]结尾
            mMax = max(mMax, dp[i]);
        }
        return mMax;
    }
};
