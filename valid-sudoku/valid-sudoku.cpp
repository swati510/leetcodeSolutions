class Solution {
public:
    bool check(int num,int r,int c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(r!=i&&board[i][c]-'0'==num)return false;
        }
         for(int i=0;i<9;i++){
            if(c!=i&&board[r][i]-'0'==num)return false;
        }
        int ind=r-r%3;
        int cind=c-c%3;
       // if(r==2&&c==2)cout<<ind<<cind;
      //  cout<<"ki";
  //      if(ind==0&&cind==0)cout<<num;
        for(int i=ind;i<ind+3;i++){
            for(int j=cind;j<cind+3;j++){
                if(board[i][j]-'0'==num){
                    if(i==r&&c==j)continue;
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!check(board[i][j]-'0',i,j,board))return false;
                }
            }
        }
        return true;
    }
};