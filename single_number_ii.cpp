class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // method 1 (using XOR, &) approach
        int ones = 0;
        int twos = 0;
        for(auto ele: nums){
            ones = (ones^ele) & (~twos);
            twos = (twos^ele) & (~ones);
        }
        return ones;
     
      /*  
      //method 2
      //sorting and linear search
        int n= nums.size();
        if(n<3){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        int i=1;
        while(i<n){
            if(nums[i]!=nums[i-1]){
                return nums[i];
                i+=3;
            }
        }
        return nums[n-1];
    */
    }
};
