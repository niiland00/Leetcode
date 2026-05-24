#include <queue>
#include <vector>
using namespace std;

class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;

        //建立鄰接清單(adjcorydist)
        vector<vector<int>> graph(n);
        //將edges裡的內容拿出查看並命名為edge
        for(const vector<int>& edge:edges){
            //因為是無向圖，起點放進終點的清單；終點放進起點的清單
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        vector<bool> visited(n,false);//預設都還沒走過
        q.push(source);
        visited[source]=true;

        while(!q.empty()){
            int currentVertex=q.front();
            q.pop();

            if(currentVertex==destination) return true;

            //現正節點的所有鄰居
            for(int neighbor:graph[currentVertex]){
                //中沒跑過的
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};
