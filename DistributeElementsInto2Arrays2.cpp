class SegmentTree{
    int n;
    vector<int>tree;
    public:
    SegmentTree(int m){
        n = m;
        tree.resize(4*n,0);
    }
    void update(int node, int l, int r, int idx){
        if(l == r and r == idx){
            tree[node]++;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid){
            update(2*node, l , mid, idx);
        }
        else{
            update(2*node+1, mid+1, r, idx);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    void updateUtil(int idx){
        update(1,1,n,idx);
    }
    int query(int node , int qL, int qR, int l, int r){
        if(qL > r or qR < l)return 0;
        if(l >= qL and r <= qR)return tree[node];
        int mid = l+(r-l)/2;
        return query(2*node , qL, qR, l, mid) + query(2*node+1 , qL, qR, mid+1, r);
        
    }
    int queryUtil(int qL, int qR){
        return query(1,qL,qR,1,n);
    }
};


class Solution {
    SegmentTree *st1, *st2;
public:
    int getRank(unordered_map<int,int>&mp, int key){
        return mp[key];
    }
    vector<int> resultArray(vector<int>& nums) {
        vector<int>val = nums;
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        // 3123  ---> 1,2,3   -->
        int m = val.size();
        unordered_map<int,int>mp;
        for(int i=0; i<m; i++){
            mp[val[i]] = i+1;
        }


        vector<int> arr1, arr2;
        st1 = new SegmentTree(m);
        st2 = new SegmentTree(m);
        arr1.push_back(nums[0]);
        st1->updateUtil(getRank(mp,nums[0]));
        arr2.push_back(nums[1]);
        st2->updateUtil(getRank(mp,nums[1]));
        for(int i= 2; i<nums.size(); i++){
            int rank = getRank(mp, nums[i]);
            int greater1 = st1->queryUtil(rank+1, m);
            int greater2 = st2->queryUtil(rank+1,m);
            if(greater1 > greater2){
                arr1.push_back(nums[i]);
                st1->updateUtil(rank);
            }
            else if(greater1 < greater2){
                arr2.push_back(nums[i]);
                st2->updateUtil(rank);
            }
            else{
                if(arr1.size() <= arr2.size()){
                    arr1.push_back(nums[i]);
                    st1->updateUtil(rank);
                }
                else{
                    arr2.push_back(nums[i]);
                    st2->updateUtil(rank);
                }
            }
        }
        vector<int>res;
        for(int i=0; i<arr1.size(); i++)res.push_back(arr1[i]);
        for(int i=0; i<arr2.size(); i++)res.push_back(arr2[i]);
        return res;
    }
};