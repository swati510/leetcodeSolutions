class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m)return findMedianSortedArrays(nums2,nums1);
        if(n==0){
            if(m%2)return nums2[m/2];
            else return (nums2[(m-1)/2]+nums2[m/2])/2.0;
        }
        int lmin=0,lmax=n,len=(n+m+1)/2;
        while(lmin<=lmax){
            int i=(lmin+lmax)/2;
            int j=len-i;
            if(i>0&&nums1[i-1]>nums2[j]){
                lmax=i-1;
            }
            else if (i < n &&  nums2[j-1] > nums1[i])
            lmin = i + 1;
            else {
                int maxleft,minRight;
                if(i==0)maxleft=nums2[j-1];
                else if(j==0)maxleft=nums1[i-1];
                else maxleft=max(nums2[j-1],nums1[i-1]);
                if(i==n)minRight=nums2[j];
                else if(j==m)minRight=nums1[i];
                else minRight=min(nums2[j],nums1[i]);
                if((n+m)%2)return maxleft;
                else return (maxleft+minRight)/2.0;
                
            }
            
            
            
        }
        return 0;
    }
};