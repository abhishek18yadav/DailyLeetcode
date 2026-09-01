class Solution {
public:
    vector<pair<int,int>>dir = {{0,1},{-1,0},{1,0},{0,-1}};
    int minMoves(vector<string>& cls, int energy) {

        struct state{
            int r;
            int c;
            int msk;// litter
            int dst;
            int en;
        };


        int m = cls.size();
        int n = cls[0].size();
        int sr = -1,sc = -1;
        vector<vector<int>>id(m, vector<int>(n,-1));
       
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(cls[i][j] == 'S'){
                    sr = i;
                    sc = j;
                }
                if(cls[i][j] == 'L')id[i][j] = cnt++;
            }
        }
         vector<vector<vector<int>>>bst(m, vector<vector<int>>(n, vector<int>(1<<cnt, -1)));
        int Flmsk = (1<<cnt)-1;
        queue<state> qu;
        qu.push({sr,sc,0,0,energy});
        while(!qu.empty()){
            state temp = qu.front();
            qu.pop();
            if(temp.msk == Flmsk){
                return temp.dst;
            }
            if(temp.en == 0)continue;
            for( auto d : dir){
                int nr = d.first + temp.r;
                int nc = d.second + temp.c;
                if(nr < 0 or nr >= m or nc <0 or nc >= n)continue;
                if(cls[nr][nc] == 'X')continue;
                int newEn = temp.en -1;
                int newDst = temp.dst +1;
                int nwMsk = temp.msk;
                if(cls[nr][nc] == 'R')newEn = energy;
                if(cls[nr][nc] == 'L'){
                    nwMsk = (1 << id[nr][nc]) | nwMsk;
                }
                if(bst[nr][nc][nwMsk] >= newEn){
                    continue;
                }
                bst[nr][nc][nwMsk]  = newEn;
                qu.push({nr,nc,nwMsk,newDst, newEn});
            }
        }
        return -1;
    }
};