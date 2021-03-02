class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>m;
        int start=0,maxm=0;
        for(int i=0;i<s.length();i++){
            
            while(m.find(s[i])!=m.end())
               
                {
                    m[s[start]]--;
                    if(m[s[start]]==0)m.erase(s[start]);
                    start++;
                }
              // m.erase(s[i]);
                
            
            m[s[i]]++;
             maxm=max(maxm,(i-start+1));
        }
        return maxm;
    }
};