class Solution {
public:
    vector<vector<char>>g;
    vector<vector<vector<int>>>dp;
    bool check(int i, int j, int open){
        if(i >= g.size() or j >= g[0].size())return false;
        if(g[i][j] == '(')open++;
        else open --;
        if(open < 0)return false;
        if(i == g.size()-1 and j == g[0].size()-1){
            if(open == 0)return true;
            return false;
        }
        if(dp[i][j][open] != -1)return dp[i][j][open];
        bool right = check(i,j+1,open);
        bool down = check(i+1,j,open);
        return dp[i][j][open] =  right or down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        g = grid;
        int n = g.size();
        int m = g[0].size();
        int max_open = n+m;
        dp.assign(n, vector<vector<int>>(m, vector<int>(max_open, -1)));
        return check(0,0,0);
    }
};