class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0, subs = 1000;

        while(n >= subs){
            res += (n-subs)+1;
            subs  = subs * 1000;
        }
        return res;
    }
};
