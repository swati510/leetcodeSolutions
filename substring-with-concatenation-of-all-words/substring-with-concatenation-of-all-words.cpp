// class Solution {
// public:
    
//     vector<int> findSubstring(string st, vector<string>& words) {
//         vector<int> res;
//         map<string,int>m;
//         map<string,int>s;
//         for(auto i:words)m[i]++;
//         for(auto i:words)s[i]=0;
//         int n=st.length();
//         int sz=words[0].size();
//         int start=0;
//         int count=0;
       
//         for(int i=0;i<n;i++){//barfoothefoobarman
//             string str=st.substr(i,sz);
//             if(m.count(str)){
//                 while(s[str]==m[str]){
//                     s[st.substr(start,sz)]--;
//                     start+=sz;
//                     count--;
//                 }
                
//                 if(s[str]<m[str]){
//                     s[str]++;
//                     count++;
//                     i+=sz-1;
//                 }
//                // if(i==14){
//                //     cout<<count;
//                // }
//                 if(count==words.size()){
//                     res.push_back(start);
//                     s[st.substr(start,sz)]--;
//                     count--;
//                     start=start+sz;
//                 }
//             }
//             else{
//                 for(auto w:words)s[w]=0;
//                 count=0;
//                 start=i+1;            

//             }
           
            
//         }
//         return res;
        
        
//     }
// };
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        map<string,int>count;
        int sz=words[0].size();
        int n=words.size();
        int w=n*sz;
        if(w>s.size())
        {
            return {};
        }
        for(auto i:words){
            count[i]++;
        }
        string t=s.substr(0,w);
        map<string,int>curr;
        for(int j=0;j<t.size();j+=sz)
        {
            curr[t.substr(j,sz)]++;
        }
        if(curr==count)
        {
            ans.push_back(0);
        }
        curr.clear();
        for(int i=1;i<=s.size()-w;i++)
        {
            t.erase(0,1);
            t.push_back(s[i+w-1]);
            for(int j=0;j<t.size();j+=sz)
            {
                curr[t.substr(j,sz)]++;
            }
            if(curr==count)
            {
                ans.push_back(i);
            }
            curr.clear();
        }
        return ans;
    }
};