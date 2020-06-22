class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();
        vector<vector<int>> t(r,vector<int>(c));
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i==r-1 && j==c-1){
                    t[i][j] = min(0,dungeon[i][j]);
                }
                else if(i==r-1){
                    t[i][j] = min(0,dungeon[i][j]+t[i][j+1]);
                }
                else if(j==c-1){
                    t[i][j] = min(0,dungeon[i][j]+t[i+1][j]);
                }
                else{
                    t[i][j] = min(0, dungeon[i][j]+max(t[i][j+1],t[i+1][j]));
                }
                
            }
            
        }
        return abs(t[0][0])+1;
        
    }
};
