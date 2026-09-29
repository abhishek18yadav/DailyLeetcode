#include <bits/stdc++.h>
using namespace std;

long long MaximumValue(vector<long long> &nums)
{
    long long val = LLONG_MIN;
    for (long long ele : nums)
    {
        val = max(val, ele);
    }
    return val;
}
vector<bool> SieveOfEratothenes(long long maximumValue)
{ // Time complexity - O(n log logn )
    long long sqrtValue = sqrt(maximumValue);
    vector<bool> PrimeNo(sqrtValue + 1, true);
    PrimeNo[0] = false;
    PrimeNo[1] = false;
    for (long long i = 2; i <= sqrtValue; i++)
    {
        if (PrimeNo[i])
        {
            for (long long j = i * i; j <= sqrtValue; j += i)
            {
                PrimeNo[j] = false;
            }
        }
    }
    return PrimeNo;
}
vector<bool> T_Primes(vector<long long> &nums)
{
    long long maximunValue = MaximumValue(nums);
    // cout<<maximunValue<<endl;

    vector<bool> PrimeNo = SieveOfEratothenes(maximunValue);
    // for(int i=0; i<PrimeNo.size(); i++){
    //     cout<<PrimeNo[i]<<" ";
    // }

    vector<bool> result(nums.size(), false);
    // unordered_set<long>st;
    // for (int i = 0; i<PrimeNo.size(); i++){
    //     if(PrimeNo[i])st.insert(i*i);
    // }
    for (int i = 0; i < nums.size(); i++)
    {
        long long sqroot = round(sqrt(nums[i]));
        if (sqroot * sqroot == nums[i] && sqroot < PrimeNo.size() && PrimeNo[sqroot])
        {
            result[i] = true;
        }
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n)
    {
        vector<long long> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<bool> result = T_Primes(nums);
        for (int i = 0; i < n; i++)
        {
            if (result[i])
                cout << "YES"<<endl;
            else
                cout << "NO"<<endl;
        }
    }

    return 0;
}

//--------------------------------------------Recursive non acceptable approach -------------------------------------------------------
// #include<bits/stdc++.h>
// using namespace std;

// vector<long long> dp;
// long long  countDivisors(int n){
//     if(n == 1)
//         return 1;
//     if(dp[n] != 0)return dp[n];
//     for (int i = n; i > 1; i--){
//         if(n % i == 0){
//             dp[n] +=  countDivisors(n / i);
//         }
//     }
//     return dp[n] ;
// }
// vector<bool> T_Factors(vector<int>& nums){
//     dp.resize(1000000000002,0);
//     vector<bool>result(nums.size(),false);
//     for(int i=0; i<nums.size(); i++){
//         // cout<<nums[i]<<" ";
//         int res = countDivisors(nums[i]);
//         // cout<<res<<" ";
//         if(res == 2){
//             result[i] = true;
//         }
//     }
//     cout<<endl;
    // for(int ele : dp){
    //     cout<<ele<<" ";
    // }
//     return result;
// }
// int main(){
//     int n;
//     if(cin>>n){
//         vector<int> nums(n);
//         for(int i=0; i<n; i++){
//             cin>>nums[i];
//         }
//         vector<bool> result = T_Factors(nums);
//         for(int i=0; i<n; i++){
//             if(result[i])
//                 cout<<nums[i]<<" ";
//         }
//     }
//     // vector<int> nums = {6};
//     // vector<bool>ans = T_Factors(nums);
    
//     return 0;
// }

