class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor=image[sr][sc];
        if(oldColor==newColor){
            return image;
        }
        int m=image.size(),n=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            for(auto i:dir){
                int x=i[0]+p.first,y=i[1]+p.second;
                if(x>=0 and x<m and y>=0 and y<n and image[x][y]==oldColor){
                    q.push({x,y});
                    image[x][y]=newColor;
                }
            }
        }
        return image;
    }
};