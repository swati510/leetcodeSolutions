class Solution {
public:
    int binarySearch(int start,int end,vector<int>& a, int target){
       if(start<=end){ int mid=(start+end)/2;
                  if(a[mid]==target)return mid;
                     if(a[mid]>target)return  binarySearch(start,mid-1,a,target);
                else return  binarySearch(mid+1,end,a,target);     
                    
                    }
        return -1;
    }
    int search(vector<int>& a, int target) {
        int s=0;
        int en=a.size();
        if(en==1){
         return a[0]==target?  0:  -1;  
        } 
        int n=en;
        en--;
        while(s<en){
            int mid=(s+en)/2;
            if(a[mid]>a[en])s=mid+1;
            else en=mid;
            
        }
        int ind=binarySearch(0,s-1,a,target);
        if(ind==-1)ind=binarySearch(s,n-1,a,target);
        return ind;
        
        
    }
};