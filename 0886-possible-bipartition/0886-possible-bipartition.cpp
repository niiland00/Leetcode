class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        //題目標記從1到n，容量要n+1
        vector<vector<int>> graph(n+1);
        for(vector<int>& dislike:dislikes){
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }

        //用標記檢測隊伍裡的敵人
        vector<int> stamp(n+1,0);

        for(int i=1;i<=n;i++){
            //已標記跳過
            if(stamp[i]!=0) continue;

            stamp[i]=1; 
            stack<int> s;
            s.push(i);

            while(!s.empty()){
            int currentVertex=s.top();
            s.pop();

                for(int enemy:graph[currentVertex]){
                    if(stamp[enemy]==0){
                        stamp[enemy]=-stamp[currentVertex];
                        s.push(enemy);
                        //丟進去後繼續檢查敵人的敵人
                    }
                    else if(stamp[enemy]==stamp[currentVertex]) return false;
                }
           }
        }
        return true;
    }
};