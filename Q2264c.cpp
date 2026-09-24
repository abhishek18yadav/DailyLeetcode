#include<bits/stdc++.h>
using namespace std;

void costFun(vector<int>&skat){
    sort(skat.begin(), skat.end(), greater<int>());

    // vector<vector<int>> subsSet(skat.size()-1, vector<int>()); //  __3__ | ___6,3_ | ___8,5,2_ | ____
  
    // for(int i=1; i<skat.size(); i++){
    //     vector<int> temp;
    //     int diff = abs(skat[i] - skat[i-1]); 
    //     temp.push_back(diff);
    //     if(i>1){
    //         for (int j = 0; j < subsSet[i - 2].size(); j++)
    //         {
    //             temp.push_back(subsSet[i - 2][j] + diff);
    //         }
    //     }
    //     subsSet[i-1] = temp;
    //     temp.clear();
    // }
    vector<int>subsets(skat.size()-1);
    vector<int> size(skat.size() - 1);
    vector<int> sum(skat.size() - 1);
    size[0] = 1;
    for (int i = 1; i<skat.size(); i++){
        int diff = skat[i-1] - skat[i];
        sum[i - 1] = diff;
        if(i >1){
            size[i-1] = size[i-2] + 1;
            sum[i-1] += diff * size[i-2] + sum[i-2];
        }
        subsets[i-1] = sum[i-1];
    }
        
    /// 
    for(int i=0; i<subsets.size(); i++){
        cout<<subsets[i]<<" ";
    }
    cout<<endl;
        // my set of subset is ready
        int combinations = 1;
        for (int i = 1; i <= subsets.size(); i++)
        {
            combinations *= i;
        }
        cout<<combinations<<endl;
    long long res = 0LL;
    // for(vector<int> &sub: subsSet){
    //     long long sum = accumulate(sub.begin(), sub.end(), 0LL);
    //     int contributionOfEchEleInSub = combinations/sub.size();
    //     res += contributionOfEchEleInSub * sum;
    // }
    //     {{3},{3,6}{2,5,8}{1,3,6,9}} ===> but now due to optimised version we have {{3},{9}{15}{19}} , i 1d only
    for(int k=0; k<subsets.size(); k++){
        long long sum = subsets[k];
        int contributionOfEchEleInSub = combinations/(k+1);
        res += contributionOfEchEleInSub * sum;
    }
    
    cout<<res<<endl;
    return;
}
int main(){
    vector<int> skat = {4,3,2,1};
    costFun(skat);
    return 0;
}

////////////////////////////////////ADVANCED VERSION

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

// Modular inverse using Fermat's Little Theorem
ll modPow(ll a, ll b)
{
    ll res = 1;

    while (b)
    {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

void costFun(vector<ll> &skat)
{

    int n = skat.size();

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    sort(skat.begin(), skat.end(), greater<ll>());

    /*
        subsets[k] represents:

        sum of costs from skat[k+1]
        to all stronger skaters before it.

        Example:

        skat = {10, 7, 4, 2, 1}

        differences:
        3, 3, 2, 1

        subsets:
        {3, 9, 15, 19}
    */

    vector<ll> subsets(n - 1);

    subsets[0] = (skat[0] - skat[1]) % MOD;

    for (int i = 2; i < n; i++)
    {

        ll diff = skat[i - 1] - skat[i];

        /*
            Previous subset contains (i-1) elements.

            Every previous cost gets +diff,
            and we also add diff itself.

            newSum =
                previousSum
                + diff * (i-1)
                + diff
        */

        subsets[i - 1] =
            (subsets[i - 2] + diff * i) % MOD;
    }

    /*
        combinations = (n-1)!

        contribution for subsets[k]:

        (n-1)! / (k+1)

        Since we are working modulo MOD,
        division is done using modular inverse.
    */

    ll combinations = 1;

    for (int i = 1; i <= n - 1; i++)
    {
        combinations = combinations * i % MOD;
    }

    ll res = 0;

    for (int k = 0; k < n - 1; k++)
    {

        ll inverse = modPow(k + 1, MOD - 2);

        ll contribution = (combinations * inverse) % MOD;

        res = (res + contribution * subsets[k]) % MOD;
    }

    cout << res << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        vector<ll> skat(n);

        for (int i = 0; i < n; i++)
        {
            cin >> skat[i];
        }

        costFun(skat);
    }

    return 0;
}