class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int mid=0,low=0,high=n-1;
      while(mid<=high){  
      switch(nums[mid])
            {
                case 0:
                    swap(nums[mid], nums[low]), low++, mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high]),high--;
                    break;
            }
       }}
    };
