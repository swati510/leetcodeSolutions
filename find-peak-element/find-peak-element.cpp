class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        int low=0;
        int high=n-1;
        a.push_back(INT_MIN);
        while(low<high){
            int mid=(low+high)/2;
            if(a[mid]<a[mid+1])low=mid+1;
            else high=mid;
        }
        return low;
        
    }
};