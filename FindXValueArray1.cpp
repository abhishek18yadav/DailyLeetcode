class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>ans(k,0);
        vector<long long>dp(k,0);
        for(int i=0; i<nums.size(); i++){
            vector<long long> ndp(k,0);
            ndp[nums[i] % k]++;
            for(int j = 0; j<k; j++){
                ndp[(long long)j * nums[i] % k] += dp[j];
            }
            dp = ndp;
            for(int r = 0; r<k; r++){
                ans[r]+= dp[r];
            }
        }
        return ans;
    }
};