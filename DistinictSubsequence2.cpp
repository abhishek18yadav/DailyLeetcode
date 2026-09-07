class Solution {
public:
vector<int>dp;
    #define mod 1000000007
    int f(string &s , int idx){
        if(idx == s.length())return 0;
        if(dp[idx] != -1)return dp[idx];
        int ans = 0;
        unordered_set<char>vis;
        for(int i=idx ; i<s.length(); i++){
            if(vis.count(s[i]))continue;
            vis.insert(s[i]);
            ans  =( ans%mod + 1 + f(s ,i+1 )%mod)%mod;
        }
        // abcaz
            // a->
            // b->
            //c->
            //a->  {continue}
            // z->
    
        return dp[idx] = ans;
    }
    int distinctSubseqII(string s) {
        dp.resize(2001, -1);
        return f(s,0);
    }
};