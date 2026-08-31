/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        int idx = 1;
        while(curr->next){
            if(curr->val > prev->val and curr->val > curr->next->val)ans.push_back(idx);
            if(curr->val < prev->val and curr->val < curr->next->val)ans.push_back(idx);
            prev = curr;
            curr = curr->next;
            idx++;
        }
        
        int minDis =INT_MAX;
        if(ans.size() < 2)return {-1,-1};
        for(int i=0; i<ans.size()-1; i++){
            minDis = min(minDis , (ans[i+1]-ans[i]));
        }
        int maxDis = ans[ans.size()-1] - ans[0];
        return {minDis , maxDis};
    }
};