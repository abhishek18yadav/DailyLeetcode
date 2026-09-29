#include<bits/stdc++.h>
using namespace std;
//////////----REGISTRATION SYSTEM------------///////////
string generatedResponse(string inp, unordered_map<int,int> &mp){
    long long sum = 0;
    for(char c : inp){
        int asciiVal = c - 'a';
        sum += asciiVal;
    }
    sum = sum % (INT_MAX-1);
    if(mp.find(sum) != mp.end()){
        return "OK";
        mp[sum] = 1;
    }else{
        int strVal = mp[sum] ;
        mp[sum]++;
        return inp+to_string(strVal);
    }
}


int main(){
    int n;
    if(cin>>n){
        unordered_map<int,int> mp;
        while(n--){
            string inp;
            cin >> inp;
            
            cout<<generatedResponse(inp,mp)<<endl;
        }
    }
    return 0;
}