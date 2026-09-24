class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;
        int left = 0, right = 0;
        int sm = 0;
        int size = nums.size();
        int ans = INT_MIN;
        if (target == 0)
            return size;
        while (right < size)
        {
            sm += nums[right];

            while (sm >= target and left <= right)
            {

                if (sm == target)
                {
                    ans = max(ans, right - left + 1);
                    cout << left << right << ans << " ";
                }
                sm -= nums[left];
                left++;
            }
            right++;
        }
        return ans == INT_MIN ? -1 : size - ans;
    }
};