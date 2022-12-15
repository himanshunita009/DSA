int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for(int i =n-1;i>1;i--){
        if(nums[i]+nums[i-1] > nums[i-2] && nums[i-2]+nums[i] > nums[i-1] && nums[i-2]+nums[i-1] > nums[i] )
            return nums[i]+nums[i-1]+nums[i-2];
    }
    return 0;
}