class Solution {
public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    vector<vector<int>> tree(n+1);
    for(int i = 0; i < edges.size(); i++)                                      //construct tree (ordered) 
      if(edges[i][0] < edges[i][1]) tree[edges[i][0]].push_back(edges[i][1]);  //reverse edge for edges[a,b] if b < a
      else tree[edges[i][1]].push_back(edges[i][0]);
    
    queue<pair<int,int>> q;                               //BFS queue <index of vertex, probability for it>
    q.push({1,1});
    while(!q.empty() ){
      int n_level_vertex = q.size();                      //count of number of vertexes for current layer
      
      while(n_level_vertex--){                            //view vertexes from current layer
        auto [vertex, probability] = q.front(); q.pop();
        
        if(vertex == target)                              //if current vertex is target
          if(tree[vertex].size() == 0 || t-- == 0) return (double)1/probability;   
          else return 0.0;
                
        probability *= tree[vertex].size();               //for next layer
        
        for(int j = 0; j < tree[vertex].size(); j++)
          q.push({tree[vertex][j],probability});
      }
      
      if(t-- == 0) break;                                 //if time is out
    }
   
    return 0.0;
  }
};