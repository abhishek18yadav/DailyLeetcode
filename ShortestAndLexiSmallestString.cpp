
class Solution {
public:
#define pp pair<int,int>
    string shortestBeautifulSubstring(string s, int k) {
        vector<int>idx;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1')idx.push_back(i);
        }
        int minval = INT_MAX;
        vector<pp>ans;
        int i=0,j=i+k-1;
        while(j<idx.size()){
            if(minval > (idx[j]-idx[i])+1){
                ans.clear();
                ans.push_back({i,j});
                minval = (idx[j]-idx[i])+1;
            }
            else if(minval == (idx[j]-idx[i])+1){
                ans.push_back({i,j});
            }
            i++;j++;
        }
        if(ans.size()==0)return "";
        pp temp = ans[0];
        string res = s.substr(idx[temp.first], idx[temp.second] - idx[temp.first] +1);
        for(pp ele : ans){
            string ss = s.substr(idx[ele.first], idx[ele.second] - idx[ele.first] +1);
            if(ss < res)res = ss;
        }
    
        return res;
    }
};