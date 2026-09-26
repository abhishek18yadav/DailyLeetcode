#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;  
int f(vector<int>&score, int i, int j){
    if(i >= score.size() and j >= score.size())return 0;
    if(i >= score.size() and j < score.size())return 0;
    if(i < score.size() and j >= score.size())return 1;
    if(dp[i][j] != -1)return dp[i][j];
    // if( j >= score.size() and i < score.size())return 1;
    if(score[j] == score[i] and j != i){
        int size = j - i + 1;
        // cout<<" size "<<size<<endl;
        // int NoOfInnerPair = size / 2;
        // int ProductOfInnerPair = NoOfInnerPair * NoOfInnerPair;
        int innersize = j - i - 1;
        // return (size * size) - (innersize <= 0 ? 0 : innersize * innersize) ;
        int ans = (size * size);
        int ans2 = f(score, j+ 1, j + 1);
        return dp[i][j] =  ans + ans2;
    }
    
    int sel = f(score, i, j + 1); 
    int notsel = 1+f(score, i + 1, j+1 );
    cout<<sel<<" "<<notsel<<endl;
    return dp[i][j]= max(sel, notsel);
}
int MaximizeTheScore(vector<int>&score){
    dp.resize(score.size(), vector<int>(score.size(), -1));
    return f(score, 0, 0);
}
int main(){
    vector<int> score = {1,1,2,3,3,2};
    cout<<MaximizeTheScore(score);
    // MaximizeTheScore(score);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// 1D DP table: dp[i] stores the max score starting from index i
// Uses O(N) memory instead of O(N^2)
vector<long long> dp;
vector<int> partner;

long long f(vector<int> &score, int i)
{
    if (i >= score.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];

    // Choice 1: Treat score[i] as a singleton (+1 point)
    long long notsel = 1 + f(score, i + 1);

    // Choice 2: Match score[i] with its partner to form a block
    long long sel = 0;
    int j = partner[i];
    if (j > i)
    { // Make sure we only pair with a duplicate ahead of us
        long long size = j - i + 1;
        sel = (size * size) + f(score, j + 1);
    }

    return dp[i] = max(sel, notsel);
}

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    int m = 2 * n;
    vector<int> score(m);
    for (int i = 0; i < m; i++)
    {
        cin >> score[i];
    }

    // Allocate only 1D arrays of size m (Safe from MLE)
    dp.assign(m, -1);
    partner.assign(m, -1);

    // Precalculate where the partner of each element is in O(N)
    vector<int> last_seen(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int val = score[i];
        if (last_seen[val] != -1)
        {
            int first_pos = last_seen[val];
            partner[first_pos] = i;
            partner[i] = first_pos;
        }
        else
        {
            last_seen[val] = i;
        }
    }

    cout << f(score, 0) << "\n";
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}
