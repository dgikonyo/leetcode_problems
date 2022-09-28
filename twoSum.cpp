vector<int> twoSum(vector<int> &nums, int target)
{
    //solution_1
     unordered_map<int, int> pair;
     vector<int> sol;

    for (int count = 0; count < nums.size(); count++)
    {
        if (pair.find(target - nums[count]) != pair.end())
        {
            sol.push_back(pair[target - nums[count]]);
            sol.push_back(count);
            return sol;
        }
        pair[nums[count]] = count;
    }
    return sol;

    //solution 2 -  doesn't work well with odd numbered array items
    sort(nums.begin(), nums.end());
    int vecsize = nums.size();
    int left = 0;
    int right = vecsize - 1;
    vector<int> sol;

    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            sol.push_back(left);
            sol.push_back(right);
            left++;
            right++;
            return sol;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return {};
}