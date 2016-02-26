class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = nums.size();
        int s,e,mid;
        s = 0;e = l-1;
        if(l==2)
            return nums[0]<nums[1]?nums[0]:nums[1];
        while(s<e)
        {
            mid = (s+e)/2;
            
            if(nums[mid]<nums[e])
                e = mid;
            else if(nums[mid]>nums[e])
                s = mid+1;
                if(e-s==1)
             return nums[e]<nums[s]?nums[e]:nums[s];
           
            
        }
        return nums[s];
        
    }
};
