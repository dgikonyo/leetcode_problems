class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        
        int left;
        int right;
        int start;
        
        left = start + 1;
        right = nums.size() - 1;
        
        for (start = 0; start < nums.size(); start++)
        {
            if (start != 0 && nums[start] == nums[start - 1]) 
                continue;
            
            int sum = nums[start] + nums[left] + nums[right];
            
            while (left < right)
            {
                if (sum == 0)
                {
                    sol.push_back({nums[start],nums[left],nums[right]});
                    ++left;
                }
                else if (sum < 0)
                {
                    ++left;
                }
                else
                    --right;
            }
        }
        return sol;
    }
};