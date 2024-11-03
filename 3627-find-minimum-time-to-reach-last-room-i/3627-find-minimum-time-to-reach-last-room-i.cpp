class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        //use a min heapd tp process the ndoes with the min time 
        //distance x y 
        int n =moveTime.size();
        int m =moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        // create a maxtrix to store the min distance 
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        dist[0][0]=0;
        pq.push({0,{0,0}});

            vector<vector<int>> dir ={{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty()){
            int t =pq.top().first;
            int sx =pq.top().second.first;
            int sy =pq.top().second.second;
            if(sx==n-1 && sy==m-1)return t;
            pq.pop();
            for(auto i:dir){
                int nx =sx+i[0];
                int ny =sy+i[1];

                //check if new coordinaties are valid 
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int newT =max(t,moveTime[nx][ny])+1;
                    if(newT <dist[nx][ny]){
                        //then update and push it into queue ;
                        dist[nx][ny] =newT;
                        pq.push({newT,{nx,ny}});
                    }
                }
            }
        }
        return -1;
    }
};